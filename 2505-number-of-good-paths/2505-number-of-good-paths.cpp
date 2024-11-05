class DisjointSet{
public:
    vector <int> size,parents;
    DisjointSet(int n){
        size.resize(n,1);
        parents.resize(n);
        for(int i=0;i<n;i++) parents[i]=i;
    }

    int findUltimateParents(int a){
        if(a==parents[a]) return a;
        return parents[a] = findUltimateParents(parents[a]);
    }
    void merge(int a, int b){
        int UltimateParents_A=findUltimateParents(a);
        int UltimateParents_B=findUltimateParents(b);
        if(UltimateParents_A==UltimateParents_B) return;

        if(size[UltimateParents_A] >= size[UltimateParents_B] ){
            parents[UltimateParents_B]=UltimateParents_A;
            size[UltimateParents_A]+=size[UltimateParents_B];
        }
        else{
            parents[UltimateParents_A]=UltimateParents_B;
            size[UltimateParents_B]+=size[UltimateParents_A];
        }
    }
};

class Solution {
public:

    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r;  // Take advantage of symmetry, nCr == nC(n-r)

        int result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size(),ans=n;
        DisjointSet* dsu= new DisjointSet(n);
        
        vector<vector<int>> adj(n);

        map<int,vector<int>> mp;    // val -> {nodes}
        vector<bool> active(n,false);

        for(auto &i:edges){
            int e1=i[0], e2=i[1];
            adj[e1].emplace_back(e2);
            adj[e2].emplace_back(e1);
        }
        for (int i = 0; i < n; i++) mp[vals[i]].push_back(i); // Group nodes by their values
        
        for(auto &i: mp){

            for(auto &j: i.second){
                active[j]=true;
                for(auto &k: adj[j]){
                    if(active[k]  && vals[k] <= i.first) dsu->merge(k,j);
                }
            }

            unordered_map<int,int> ump;
            for(auto &j: i.second){
                int p=dsu->findUltimateParents(j);
                ump[p]++;
            }

            for(auto &j: ump) if(j.second>=2) ans+= nCr(j.second,2);
        }

        return ans;
    }
};