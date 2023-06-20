class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack <pair<int,int> > st;
        int maxArea=0;
        for(int i=0; i<heights.size();i++){
            int start=i;
            while(!st.empty() && st.top().second>heights[i]){
                int ar=st.top().second*( i-st.top().first );
                maxArea=max(maxArea,ar);
                start=st.top().first;
                st.pop();
            }
            st.emplace(make_pair(start,heights[i]));
        }

        int p=st.size();
        for(int i=0;i<p;i++){
            // int h=st.top().second;
            // int r=heights.size();
            // int l=st.top().first;
            // int ar=h*(r-l);
            // maxArea= max(ar,maxArea);
            int ar=(st.top().second)*(heights.size()-st.top().first);
            maxArea= max(ar,maxArea);
            st.pop();
        }
        return maxArea;
    }
};