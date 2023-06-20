class Solution {
public:
    vector<string> generateParenthesis(int n) {

        string str;
        str.append(n, '(');
        str.append(n, ')');
        vector<string> ans;
        do{
        stack <char> st;
        for(auto ch: str){
            if(ch=='('){
                st.emplace('(');
            }
            else if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
        }
        if(st.empty()){
            ans.emplace_back(str);
        }

        }while( next_permutation( str.begin(),str.end() ));

        return ans;   
    }
};