class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums.size() < 3 || nums[0] > 0) return {};
        unordered_map<int , int> hashMap;
        int n=nums.size();
        for(int i = 0 ; i<n ; i++) hashMap[nums[i]] = i;
        
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){
            if(nums[i] > 0) break;
            
            for(int j=i+1; j<n-1 ; j++){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};