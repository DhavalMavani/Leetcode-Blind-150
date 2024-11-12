class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int s=queries.size();
        vector<int> ans(s);
        for(int i=0;i<s;i++){
            int steps=1,a=queries[i][0],b=queries[i][1];
            while(a!=b){
                if(a>b) a=a>>1;
                else b=b>>1;
                steps++;
            }
            ans[i]=steps;
        }
        return ans;
    }
};