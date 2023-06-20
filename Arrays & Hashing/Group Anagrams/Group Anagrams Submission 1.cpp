class Solution {
public:

    string sortStr(string s){

        int hashArray[26]={0};

        for(auto ch: s){
            hashArray[ch-'a']+=1;
        }
        string t;
        for (int i=0;i<26;i++){
            t+= string ( hashArray[i], 'a'+i );
        }
        return t;
    }
    
    vector< vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> v1;
        unordered_map < string, vector<string> > ump;

        for ( int i=0; i<strs.size();i++ ){
            string t=strs[i];
            ump[sortStr(t) ].emplace_back(strs[i]);
        }

        for(auto i: ump){
            v1.emplace_back(i.second);
        }
        
        return v1;
    }
};