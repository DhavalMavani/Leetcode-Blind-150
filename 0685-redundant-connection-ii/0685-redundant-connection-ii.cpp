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
    bool merge(int a, int b){
        int UltimateParents_A=findUltimateParents(a);
        int UltimateParents_B=findUltimateParents(b);
        if(UltimateParents_A==UltimateParents_B) return true;

        if(size[UltimateParents_A] >= size[UltimateParents_B] ){
            parents[UltimateParents_B]=UltimateParents_A;
            size[UltimateParents_A]+=size[UltimateParents_B];
            return false;
        }
        else{
            parents[UltimateParents_A]=UltimateParents_B;
            size[UltimateParents_B]+=size[UltimateParents_A];
            return false;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> indegree(edges.size()+1,-1);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int n1=edges[i][0],n2=edges[i][1];
            if( indegree[n2]!=-1){
                DisjointSet* dsu=new DisjointSet(n+1);
                int b1=indegree[n2],b2=i;
                for(int j=0;j<n;j++){
                    if(j==b2) continue;
                    if (dsu->merge(edges[j][0],edges[j][1]) ) return edges[b1];
                }
                return edges[b2];
            }
            indegree[n2]=i;
        }

        DisjointSet* dsu=new DisjointSet(n+1);
        for(int i=0;i<n;i++) if (dsu->merge(edges[i][0],edges[i][1]) ) return edges[i];
        return {};
    }
};