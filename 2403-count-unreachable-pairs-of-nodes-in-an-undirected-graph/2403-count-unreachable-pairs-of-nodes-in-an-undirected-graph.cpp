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

        parents[UltimateParents_B]=UltimateParents_A;
        size[UltimateParents_A]+=size[UltimateParents_B];
        size[UltimateParents_B]=0;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet* dsu= new DisjointSet(n);

        for(auto &i: edges) dsu->merge(i[0],i[1]);

        long long ans=0,sum=-1;

        for(auto &i: dsu->size){
            if(i){
                if(sum==-1) sum=i;
                else{
                    ans+= sum*i;
                    sum+=i;
                }
            }
        } 

        return ans;
    }
};