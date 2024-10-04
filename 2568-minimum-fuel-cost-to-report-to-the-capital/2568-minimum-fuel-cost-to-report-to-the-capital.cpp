// cities=n
// roades=n-1 
class Solution {
public:
    int k=0;
    int dfs(int currCity,int parentCity,long long &ans,vector<vector<int>> &city){
        
        int numPassengers=0;

        for(auto &i: city[currCity]){
            if(i!=parentCity){
                int a = 1+dfs(i,currCity,ans,city);
                ans+=a/k;
                if(a%k) ans++;
                numPassengers+= a;
            }
        }
        return numPassengers;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        k=seats;
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