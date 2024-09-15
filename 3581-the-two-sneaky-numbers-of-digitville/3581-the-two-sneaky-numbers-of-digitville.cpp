class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> hash(101,0);

        for(auto &i: nums){
            hash[i]++;
            if(hash[i]==2) ans.emplace_back(i);
        }
        return ans;
    }
};