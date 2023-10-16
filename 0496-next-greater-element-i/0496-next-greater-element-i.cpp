class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> ump;
        for(int i=0;i<nums1.size();i++ ){
            ump[nums1[i]]=i;
        }

        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums2.size();i++){
            if(ump.find(nums2[i]) == ump.end() ){
                continue;
            }
            for(int j=i;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    ans[ ump[nums2[i]] ]=nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};