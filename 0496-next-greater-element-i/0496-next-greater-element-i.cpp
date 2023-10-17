class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> ump;
        for(int i=0;i<nums1.size();i++ ){
            ump[nums1[i]]=i;
        }

        vector<int> ans(nums1.size(),-1);
        stack <int> st;

        int i=0;
        while( i<nums2.size() ){
            while(!st.empty() && nums2[i]>st.top() ){
                ans[ ump[st.top()] ] =nums2[i];
                st.pop();
            }
            if( ump.find(nums2[i]) != ump.end() ){
                st.emplace(nums2[i]);
            }
            i++;

        }

        return ans;
    }
};