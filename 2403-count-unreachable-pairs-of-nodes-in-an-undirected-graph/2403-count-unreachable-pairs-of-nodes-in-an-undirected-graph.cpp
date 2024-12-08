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
            size[UltimateParents_B]=0;
        }
        else{
            parents[UltimateParents_A]=UltimateParents_B;
            size[UltimateParents_B]+=size[UltimateParents_A];
            size[UltimateParents_A]=0;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet* dsu= new DisjointSet(n);

        for(auto &i: edges) dsu->merge(i[0],i[1]);

        vector<int> arr;
        for(auto &i: dsu->size) if(i) arr.emplace_back(i);

        long long ans=0,sum=arr[0];

        for(int i=1;i<arr.size();i++){
            ans+= sum*arr[i];
            sum+=arr[i];
        }

        return ans;
    }
};