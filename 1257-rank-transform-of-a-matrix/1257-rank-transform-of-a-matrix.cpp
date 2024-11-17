class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
   
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
}; 
class Solution {
public: 
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==0 and m==0) return {{}};
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[matrix[i][j]].push_back({i,j});
            }
        }  
        vector<vector<int>> ans(n,vector<int>(m));
        vector<int> row(n,0),col(m,0);
        vector<int> rank(m+n);
        for(auto &it:mp){
            DisjointSet ds(n+m); 
            vector<pair<int,int>> v=it.second;

            for(auto &i: v) ds.unionBySize(i.first,i.second+n);

            for(auto &i: v) rank[ds.findUPar(i.first)]=max(rank[ds.findUPar(i.first)],max(row[i.first],col[i.second])); 

            for(auto &i: v) ans[i.first][i.second]=row[i.first]=col[i.second]=rank[ds.findUPar(i.first)]+1;

        }
        return ans;
    }
};