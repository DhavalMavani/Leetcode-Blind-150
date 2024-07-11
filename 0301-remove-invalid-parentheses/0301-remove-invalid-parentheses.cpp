class Solution {
public:
    unordered_set<string> ust;
    bool isValid(string s){
        int open=0,close=0,n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(close>open) return false;
        }
        return open == close;

    }
    void dfs(string &s,int extra, int ind ){
        if(extra==0){
            if(isValid(s)){
                string temp;
                for(auto &i: s) if(i!='#') temp+=i;
                ust.emplace(temp);
            }
        }
        if(ind>s.size()) return;


        // don't keep
        if(s[ind]=='(' || s[ind]==')'){
            char t=s[ind];
            s[ind]='#';
            dfs(s,extra-1, ind);
            s[ind]=t;
        }
        
        // keep
        dfs(s,extra,ind+1);

    }
    vector<string> removeInvalidParentheses(string s) {
        int open=0,close=0,n=s.size(),extra=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(close>open){
                extra++;
                open=0;
                close=0;
            }

        }
        extra+= open-close;
        dfs(s,extra,0);
        vector<string> ans;
        for(auto &i: ust) ans.emplace_back(i);

        return ans;
    }
};