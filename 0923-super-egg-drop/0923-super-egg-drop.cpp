class Solution {
public:
    //Time: O(n*k*logn), Space: O(n*k)
    int helper(int k, int n, vector<vector<int>>& dp){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            int left = helper(k-1, mid-1, dp);
            int right = helper(k, n-mid, dp);
            
            temp = 1 + max(left, right);
            if(left < right){
                low = mid+1;
            } 
            else{
                high = mid-1;
            }
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return helper(k, n, dp);
    }
};