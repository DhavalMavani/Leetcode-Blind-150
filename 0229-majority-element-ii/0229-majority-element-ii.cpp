class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set <int> st;
        int n=nums.size()/3;
        unordered_map <int,int> ump;

        for(auto i: nums){
            if(st.size()==2){
                break;
            }
            ump[i]++;
            if(ump[i]>n){
                st.emplace(i);
            }
        }

        vector<int> ans(st.begin(),st.end());
        
        return ans;
    }
};