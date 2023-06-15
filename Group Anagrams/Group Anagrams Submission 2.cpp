class Solution {
public:
    vector< vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> v1;
        unordered_map < string, vector<string> > ump;

        for ( int i=0; i<strs.size();i++ ){
            string t=strs[i];
            sort(t.begin(),t.end());
            ump[t].emplace_back(strs[i]);
        }

        for(auto i: ump){
            v1.emplace_back(i.second);
        }
        
        return v1;
    }
};