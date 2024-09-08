class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long score=0,n=nums.size(),str=0;

        while(str<n-1){
            int end=str+1;
            while(end<n-1 && nums[end]<=nums[str]) end++;
            score+= (end-str)*nums[str];
            str=end;
        }
        return score;
    }
};