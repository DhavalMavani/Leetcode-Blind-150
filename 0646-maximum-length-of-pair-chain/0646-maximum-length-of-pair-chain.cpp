class Solution {
public:
    static bool comp(vector<int> &p1, vector<int> &p2){
        return p1[1]<p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n=pairs.size(),ans=1,freeTime=pairs[0][1];
        for(int i=1;i<n;i++){
            if(pairs[i][0]>freeTime){
                freeTime=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};