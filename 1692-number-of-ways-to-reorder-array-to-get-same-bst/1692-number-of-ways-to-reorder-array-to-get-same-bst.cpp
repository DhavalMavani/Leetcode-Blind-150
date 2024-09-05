class Solution {
public:
    int m=1e9+7;
    vector<vector<int>> pascalTriangle;

    int solve(vector<int> nums){
        int n=nums.size();
        if(n<=2) return 1;
        vector<int> left;
        vector<int> right;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0]) left.emplace_back(nums[i]);
            else right.emplace_back(nums[i]);
        }

        int a=pascalTriangle[n-1][left.size()]%m;
        int b=solve(left)%m;
        int c=solve(right)%m;

        return ((((long long)a*b)%m)*c)%m;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pascalTriangle.resize(n,vector<int>(n,1));
        // calculate pascal triangle
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                pascalTriangle[i][j]=(pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j])%m;
            }
        }
        return solve(nums)-1;
    }
};