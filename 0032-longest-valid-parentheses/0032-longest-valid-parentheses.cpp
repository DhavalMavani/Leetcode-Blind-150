class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), ans=0;
        stack<int> st;
        st.emplace(-1);
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()) st.emplace(i);
                ans=max(ans,i-st.top());
            }
            else st.emplace(i);
        }
        return ans;
    }
};