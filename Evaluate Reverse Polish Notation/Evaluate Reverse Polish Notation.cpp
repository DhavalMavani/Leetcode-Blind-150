class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int ans;
        for (auto ch : tokens)
        {
            if (ch == "+")
            {
                int a = st.top();
                st.pop();
                int b = a + st.top();
                st.pop();
                st.emplace(b);
            }
            else if (ch == "-")
            {
                int a = st.top();
                st.pop();
                int b = st.top() - a;
                st.pop();
                st.emplace(b);
            }
            else if (ch == "*")
            {
                int a = st.top();
                st.pop();
                int b = a * st.top();
                st.pop();
                st.emplace(b);
            }
            else if (ch == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top() / a;
                st.pop();
                st.emplace(b);
            }
            else
            {
                st.emplace(stoi(ch));
            }
        }

        return st.top();
    }
};