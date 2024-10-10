class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &i: tasks) freq[i-'A']++;
        
        priority_queue<int> pq;
        for(auto &i: freq) if(i!=0) pq.push(i);

        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            int i=0;
            while( !pq.empty() && i<=n){
                int j=pq.top();
                pq.pop();
                if(j>1) temp.emplace_back(j-1);
                i++;
            }
            if(!temp.empty())ans+=n+1;
            else ans+=i;

            for(auto &e: temp) pq.emplace(e);
        }
        return ans;
    }
};