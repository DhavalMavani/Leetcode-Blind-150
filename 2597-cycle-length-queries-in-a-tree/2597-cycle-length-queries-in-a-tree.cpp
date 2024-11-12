class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int s=queries.size();
        vector<int> ans(s);
        for(int i=0;i<s;i++){
            int steps=1;
            while(queries[i][0]!=queries[i][1]){
                if(queries[i][0]>queries[i][1]) queries[i][0]/=2;
                else queries[i][1]/=2;
                steps++;
            }
            ans[i]=steps;
        }
        return ans;
    }
};