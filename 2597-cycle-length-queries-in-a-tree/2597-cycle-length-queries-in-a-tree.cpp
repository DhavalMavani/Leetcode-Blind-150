class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &i: queries){
            int a=i[0],b=i[1],steps=1;
            while(a!=b){
                if(a>b) a/=2;
                else b/=2;
                steps++;
            }
            ans.emplace_back(steps);
        }
        return ans;
    }
};