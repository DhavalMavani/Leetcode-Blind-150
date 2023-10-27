class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map <int,int> prefixReminder;
        prefixReminder[0]=1;
        for(auto &i: nums){
            sum+=i;
            int remainder=sum%k;
            if(remainder<0){
                remainder+=k;
            }
            ans+=prefixReminder[remainder];
            prefixReminder[remainder]++;
        }
        return ans;
    }
};