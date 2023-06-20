class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Parentheses(0,0,n,"",ans);
        return ans;
    }
    
private:
    void Parentheses(int open,int close,int n, string s,vector<string>& ans){
        if(open==n and close==n){
            ans.emplace_back(s);
            return;
        }
        if(open<n){
            Parentheses(open+1,close,n,s+"(",ans);
        }
        if(open>close){
            Parentheses(open,close+1,n,s+")",ans);
        }
    }
};