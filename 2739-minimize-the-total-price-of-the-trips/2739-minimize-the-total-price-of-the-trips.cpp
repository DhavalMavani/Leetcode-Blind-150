class Solution {
public:

    void calcContribution(int &node,int &dst,int parent, vector<int> &contribution, vector<vector<int>> &tree, vector<int> &path){
        path.emplace_back(node);
        if(node==dst){
            for(auto &i: path) contribution[i]++;
            return;
        }

        for(auto &i: tree[node]){
            if(i!=parent){
                calcContribution(i,dst,node,contribution,tree, path);
            }
        }
        path.pop_back();
    }


    int calcMinPrice(int node,int parent,int parentHalved,vector<vector<int>> &tree,vector<vector<int>> &dp, vector<int>& price){
        if(dp[node][parentHalved]!=-1) return dp[node][parentHalved];

        int notHalved=price[node], halved=price[node]/2;

        for(auto &i: tree[node]){
            if(i!=parent) notHalved+= calcMinPrice(i,node,false,tree,dp, price);
        }
        if(parentHalved) return dp[node][parentHalved]=notHalved;

        for(auto &i: tree[node]){
            if(i!=parent) halved+= calcMinPrice(i,node,true,tree,dp, price);
        }

        return dp[node][parentHalved]=min(notHalved,halved);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> tree(n);
        for(auto &i: edges){
            tree[i[0]].emplace_back(i[1]);
            tree[i[1]].emplace_back(i[0]);
        }

        vector<int> contribution(n,0);

        for(auto &i: trips){
            vector<int> path;
            calcContribution(i[0],i[1],-1, contribution,tree,path );
        }
        for(int i=0;i<n;i++) price[i]*=contribution[i];
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return calcMinPrice(0,-1,false,tree,dp,price);
    }
};