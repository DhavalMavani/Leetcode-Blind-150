class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]>v2[0];
    }


    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int n=properties.size(),ans=0, defense=properties[0][1];

        for(int i=0;i<n;i++){
            if(properties[i][1]<defense) ans++;
            else defense=properties[i][1];
        }

        return ans;
    }
};