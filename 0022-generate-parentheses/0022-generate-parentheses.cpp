class Solution {
public:
    void generate(vector<string> &ans,int open,int close,string s){
        if(!open && !close){
            ans.emplace_back(s);
            return;
        }
        if(open>0) generate(ans,open-1,close,s+'(');

        if(close>open) generate(ans,open,close-1,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,n,n,"");
        return ans;
    }
};