class Solution {

private:
    long int dfs(int n,vector <long int>&  dpArray){
        if(n==1 || n==0){
            return 1;
        }
        if(dpArray[0]!=-1 && dpArray[1]!=-1){
            return dpArray[0]+ dpArray[1];
        }
        dpArray[0]=dfs(n-2,dpArray);
        dpArray[1]=dfs(n-1,dpArray);
        return dpArray[0]+dpArray[1];
    }    
public:
    int climbStairs(int n) {
        vector <long int>  dpArray(n+1,-1);
        return dfs(n,dpArray);
    }
};