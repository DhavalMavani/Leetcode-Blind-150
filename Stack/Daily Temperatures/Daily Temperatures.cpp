class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack <pair<int,int>>  st;
        for (int i=0;i<temperatures.size();i++){
            while(!st.empty() && st.top().first<temperatures[i]){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.emplace(make_pair(temperatures[i],i));
        }
        return ans;
    }
};