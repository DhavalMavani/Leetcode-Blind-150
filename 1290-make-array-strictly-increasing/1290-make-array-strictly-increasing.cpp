class Solution {
public:
    int solve(int index,int prev,vector<int>& arr1, vector<int>& arr2,vector<unordered_map<int,int>> &dp){
        if(index==arr1.size()) return 0;
        int opt1=INT_MAX,opt2=INT_MAX;

        if(dp[index].count(prev)) return dp[index][prev];
        if(arr1[index]>prev ){
            opt1=solve(index+1,arr1[index],arr1,arr2,dp);
            auto a=upper_bound(arr2.begin(), arr2.end(), prev);
            if(a!=arr2.end() && *a<arr1[index]){
                opt2=1+solve(index+1,*a,arr1,arr2,dp);
            }
        }
        else{
            auto a=upper_bound(arr2.begin(), arr2.end(), prev);
            if(a==arr2.end() || *a<=prev) return 1e9;            
            opt2=1+solve(index+1,*a,arr1,arr2,dp);
        }
        
        return dp[index][prev]=min(opt1,opt2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<unordered_map<int,int>> dp(arr1.size());
        int ans=solve(0,-1,arr1,arr2,dp);
        if (ans>2000) return -1;
        return ans;
    }
};
























        // for(int i=1;i<n;i++){
        //     if(arr1[i-1]>=arr1[i]){

        //         auto a=upper_bound(arr2.begin(), arr2.end(), arr1[i-2]);
        //         if(a==arr2.end() ) return -1;

        //         if(*a>=arr1[i]){
        //             auto b=upper_bound(arr2.begin(), arr2.end(), *a);
        //             if(b==arr2.end()) return -1;
        //             if(*a==arr1[i-1]) ans++;
        //             else ans+=2;

        //             arr1[i-1]=*a;
        //             arr1[i]=*b;
        //         }
        //         else{
        //             arr1[i-1]=*a;
        //             ans++;
        //         }
        //     }
        // }