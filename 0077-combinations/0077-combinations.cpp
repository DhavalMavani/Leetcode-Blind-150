class Solution {
public:
    int N,K;
    vector<vector<int>> ans;
    vector<int> path;

    void helper(int num){
        if(path.size()==K){
            ans.emplace_back(path);
            return;
        }

        int req=K-path.size()-1;
        for(int i=num; i + req <= N ;i++ ){
            path.emplace_back(i);
            helper(i+1);
            path.pop_back();
        } 
    }

    vector<vector<int>> combine(int n, int k) {
        N=n,K=k;
        helper(1);
        return ans;
    }
};
