class Solution {
public:
    static bool comp(pair<int,int> &p1,pair<int,int> &p2){
        if(p1.first==p2.first) return p1.second<p2.second;
        else return p1.first>p2.first;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> sorted;
        for(int i=0;i<n;i++) sorted.push_back({arr[i],i});

        sort(sorted.begin(),sorted.end());
        vector<int> nextOdd(n,0);
        stack<int> st;
        for(auto &i: sorted){
            while(!st.empty()){
                if(i.second>st.top()){
                    nextOdd[st.top()]=i.second;
                    st.pop();
                }
                else break;
            }
            st.emplace(i.second);
        }

        sort(sorted.begin(),sorted.end(),comp);
        vector<int> nextEven(n,0);
        stack<int> st2;
        for(auto &i: sorted){
            while(!st2.empty()){
                if(i.second>st2.top()){
                    nextEven[st2.top()]=i.second;
                    st2.pop();
                }
                else break;
            }
            st2.emplace(i.second);
        }

        vector<bool> dpOdd(n,0);
        vector<bool> dpEven(n,0);
        dpOdd[n-1]=1,dpEven[n-1]=1;

        for(int i=n-2;i>=0;i--){
            if(dpEven[nextOdd[i]]==true ) dpOdd[i]=true;
            if(dpOdd[nextEven[i]]==true ) dpEven[i]=true;
        }

        int ans=0;
        for(int i=0;i<n;i++) ans+=dpOdd[i];
        return ans;
    }
};