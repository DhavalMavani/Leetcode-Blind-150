class Solution {
public:

    void merge(int left,int mid, int right,vector<int>& nums){
        vector<int> temp;
        int p1=left;
        int p2=mid+1;
        while(p1<=mid && p2<=right){
            if(nums[p1]<nums[p2]) temp.emplace_back(nums[p1]),p1++;
            else temp.emplace_back(nums[p2]),p2++;
        }
        while(p1<=mid) temp.emplace_back(nums[p1]),p1++;
        while(p2<=right) temp.emplace_back(nums[p2]),p2++;

        for(int i=left; i<=right;i++) nums[i]=temp[i-left];
    }

    void mergeSort(int left,int right, vector<int>& nums){
        if(left==right) return;

        int mid=(left+right)/2;
        mergeSort(left,mid,nums);
        mergeSort(mid+1,right,nums);
        merge(left,mid,right,nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};

