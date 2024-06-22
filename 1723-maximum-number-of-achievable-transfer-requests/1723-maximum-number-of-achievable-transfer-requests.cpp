class Solution {
public:
    int ans=0;
    void solve(int i,vector<int> &building,vector<vector<int>>& requests, int count){
        if(i>=requests.size()){
            for(auto &cnt: building) if(cnt!=0) return;
            ans=max(ans,count);
            return;
        }

        solve(i+1,building,requests,count);   // not take

        building[requests[i][0] ]-=1;
        building[requests[i][1] ]+=1;
        solve(i+1,building,requests,count+1);     // take
        building[requests[i][0] ]++;
        building[requests[i][1] ]--;

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> building(n,0);
        solve(0,building,requests,0);
        return ans;
    }
};