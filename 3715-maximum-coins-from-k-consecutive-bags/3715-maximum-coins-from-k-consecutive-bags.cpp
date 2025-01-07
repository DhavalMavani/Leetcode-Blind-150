class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());

        long long ans=0,currSum=0;
        int l=0,r=0,n=coins.size();

        while(l<n){
            while(r<n && coins[r][1]-coins[l][0]+1 <= k ){
                currSum+= (long long) (coins[r][1]-coins[r][0]+1)*coins[r][2];
                r++;
            }

            long long partialSum=0;
            if(r<n) partialSum= (long long) max(0, k - (coins[r][0]-coins[l][0]) ) *coins[r][2];

            ans=max(ans,currSum+partialSum);

            currSum-= (long long) (coins[l][1]-coins[l][0]+1)*coins[l][2];
            l++;
        }
        
        currSum=0, l=n-1,r=n-1;
        while(r>=0){

            while(l>=0 && coins[r][1]-coins[l][0]+1<=k){
                currSum+=(long long) (coins[l][1]-coins[l][0]+1)*coins[l][2];
                l--;
            }

            long long partialSum=0;
            if(l>=0) partialSum= (long long) max(0,k - (coins[r][1] -coins[l][1]) ) *coins[l][2];

            ans=max(ans,currSum+partialSum);

            currSum-= (long long) (coins[r][1]-coins[r][0]+1)*coins[r][2];
            r--;
        }

        return ans;
    }
};