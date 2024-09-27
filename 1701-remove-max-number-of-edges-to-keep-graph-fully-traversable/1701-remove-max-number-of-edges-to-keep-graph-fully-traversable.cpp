class DSU{
public:
    int s;
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        s=n;
        parent.resize(s);
        rank.resize(s,1);
        for(int i=1;i<n;i++) parent[i]=i;
    }

    int findUltimateParent(int a){
        if(a==parent[a]) return a;
        int p=findUltimateParent(parent[a]);
        return parent[a]=p;
    }

    bool merge(int a, int b){
        int ultimateParent_a=findUltimateParent(a);
        int ultimateParent_b=findUltimateParent(b);

        if(ultimateParent_a==ultimateParent_b){
            return true;
        }
        else if(rank[ultimateParent_a]>=rank[ultimateParent_b]){
            rank[ultimateParent_a]+=rank[ultimateParent_b];
            parent[ultimateParent_b]=ultimateParent_a;
            return false;
        }
        else{
            rank[ultimateParent_b]+=rank[ultimateParent_a];
            parent[ultimateParent_a]=ultimateParent_b;
            return false;
        }
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),greater<>());
        DSU* alice= new DSU(n+1);
        DSU* bob= new DSU(n+1);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                bob->merge(edges[i][1],edges[i][2]);
                if ( alice->merge(edges[i][1],edges[i][2]) ) ans++;
            }
            else if(edges[i][0]==2){
                if (bob->merge(edges[i][1],edges[i][2]) ) ans++;
            }
            else{
                if ( alice->merge(edges[i][1],edges[i][2]) ) ans++;
            }
        }

        if(alice->rank[alice->findUltimateParent(1)]<n || bob->rank[bob->findUltimateParent(1)]<n) return -1;
        return ans;
    }
};