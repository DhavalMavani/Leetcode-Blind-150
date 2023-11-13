class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={{1}};
        if(numRows==1){
            return ans;
        }
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                int sum=0;
                if(j-1>=0){
                    sum+=ans[i-1][j-1];
                }
                if(i-1>=j){
                    sum+=ans[i-1][j];
                }
                temp.emplace_back(sum);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};