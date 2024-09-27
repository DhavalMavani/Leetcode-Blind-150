class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if( n != t.size()) return false;
        
        vector<int> chars(26,0);

        for (int i=0; i<n ; i++){
            chars[s[i]-'a']++;
            chars[t[i]-'a']--;
        }
        for(int i=0;i<26;i++) if(chars[i]) return false;
        
        return true;
    }
};