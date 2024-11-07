// monotonically increasing
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            int str=i;
            while(!st.empty() && heights[st.top()] > heights[i] ){
                ans=max(ans,(i-st.top() )*heights[st.top()]);
                str=st.top();
                heights[str]=heights[i];
                st.pop();
            }
            st.emplace(str);
        }

        int s=st.size();
        for(int i=0;i<s;i++){
            ans=max(ans,(n-st.top())*heights[st.top()]);
            st.pop();
        }
        return ans;
    }
};