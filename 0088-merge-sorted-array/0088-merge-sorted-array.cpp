class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1=0,n2=0,ind=0;
        vector<int> arr(n1+n2);

        while(n1<m && n2<n){
            if(nums1[n1]<nums2[n2]) arr.emplace_back(nums1[n1]),n1++;
            else arr.emplace_back(nums2[n2]),n2++;
        }

        while(n1<m) arr.emplace_back(nums1[n1]),n1++;
        while(n2<n) arr.emplace_back(nums2[n2]),n2++;

        nums1=arr;
    }
};