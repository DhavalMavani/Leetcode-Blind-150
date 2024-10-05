class Solution {
public:
    int s=0;
    int dfs(int currCity,int parentCity,long long &ans,vector<vector<int>> &city){
        int numPassengers=0;
        for(auto &i: city[currCity]){
            if(i!=parentCity){
                int p = dfs(i,currCity,ans,city);
                ans+= p/s ;
                if(p%s) ans++;
                numPassengers+=p;
            }
        }
        return numPassengers+1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        s=seats;
        int n=roads.size();
        long long ans=0;
        vector<vector<int>> city(n+1);
        for(auto &i: roads){
            city[i[0]].emplace_back(i[1]);
            city[i[1]].emplace_back(i[0]);
        }
        dfs(0,-1,ans,city);
        return ans;
    }
};