class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int l=0,r=mat[0].size()-1,t=0,b=mat.size()-1;
        
        vector<int> ans;

        while(l<=r && t<=b){
            for(int i=l;i<=r;i++) ans.emplace_back(mat[t][i]);
            t++;

            for(int i=t;i<=b;i++) ans.emplace_back(mat[i][r]);
            r--;

            if(l>r || t>b) break;
            
            for(int i=r;i>=l;i--) ans.emplace_back(mat[b][i]);
            b--;

            for(int i=b;i>=t;i--) ans.emplace_back(mat[i][l] );
            l++;
        }

        return ans;
    }
};