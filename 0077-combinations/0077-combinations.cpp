class Solution {
public:
    int N,K;
    vector<vector<int>> ans;

    void helper(int num, vector<int> &path){
        if(path.size()==K){
            ans.emplace_back(path);
            return;
        }

        if(num > N) return;
       
        helper(num+1,path);
        path.emplace_back(num);
        helper(num+1,path);
        path.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        N=n,K=k;
        vector<int> path;
        helper(1,path);
        return ans;
    }
};
