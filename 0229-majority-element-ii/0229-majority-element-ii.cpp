class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int ct1=0,ct2=0;
        int ele1=INT_MIN, ele2=INT_MIN;

        for(int i=0;i<n;i++){
            if(ct1==0 && nums[i]!=ele2){
                ele1=nums[i];
                ct1++;
            }
            else if(ct2==0 && nums[i]!=ele1){
                ele2=nums[i];
                ct2++;
            }
            else if(nums[i]==ele1){
                ct1++;
            }
            else if(nums[i]==ele2){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        
        ct1=0;
        ct2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                ct1++;
            }
            else if(nums[i]==ele2){
                ct2++;
            }
        }

        vector<int> ans;

        if(ct1>n/3){
            ans.emplace_back(ele1);
        }
        if(ct2>n/3){
            ans.emplace_back(ele2);
        }
        
        return ans;
    }
};