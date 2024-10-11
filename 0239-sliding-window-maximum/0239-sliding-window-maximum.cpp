class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n=nums.size();
        for(int i=0;i<k;i++) s.emplace(-nums[i]);

        vector<int> ans;
        ans.emplace_back(-*s.begin());

        for(int i=k;i<n;i++){
            s.erase(s.find(-nums[i-k]));
            s.emplace(-nums[i]);
            ans.emplace_back( -*s.begin() );
        }
        return ans;
    }
};