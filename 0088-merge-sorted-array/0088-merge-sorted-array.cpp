class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1=m-1,n2=n-1,ind=m+n-1;

        while(n1>=0 && n2>=0){
            if(nums1[n1]>nums2[n2]){
                nums1[ind]=nums1[n1];
                n1--;
            } 
            else{
                nums1[ind]=nums2[n2];
                n2--;
            } 
            ind--;
        }

        while(n1>=0) nums1[ind]=nums1[n1],n1--, ind--;
        while(n2>=0) nums1[ind]=nums2[n2],n2--, ind--;
    }
};