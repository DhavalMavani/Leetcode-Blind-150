class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<int> prefix(n);
        vector<int> sufix(n);

        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i-1];
        for(int i=n-2;i>=0;i--) sufix[i]=sufix[i+1]+nums[i+1];

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(sufix[i]==prefix[i]) ans+=2;
                else if(abs(sufix[i]-prefix[i])==1) ans++;
            }
        }

        return ans;
    }
};