class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int n=nums.size()/2;
        unordered_map <int,int> ump;

        for(auto i: nums){
            ump[i]++;
        }

        for(auto i: ump){
            if(i.second>n){
                return i.first;
            }
        }
        return 0;
    }
};