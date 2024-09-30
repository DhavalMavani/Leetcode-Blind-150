class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        vector<int> char_s(128,-1);
        vector<int> char_t(128,-1);
        for(int i=0;i<n;i++){
            if( char_s[s[i]]==-1 ) char_s[s[i]]=t[i];
            else if(char_s[s[i]] != t[i] ) return false;

            if( char_t[t[i]]==-1 ) char_t[t[i]]=s[i];
            else if(char_t[t[i]] != s[i] ) return false;
        }
        return true;
    }
};