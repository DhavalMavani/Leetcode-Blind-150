class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), requiredChars=t.size();
        if(n<requiredChars) return "";
    
        unordered_map<char,int> ump;
        for(auto &i: t) ump[i]++;

        int ansInd=0, ansLen=1e9, l=0,r=0, currChars=0;

        while(r<n){
            if(ump[s[r]]>0) currChars++;
            ump[s[r]]--;
            r++;
            while(currChars==requiredChars){
                // int currLen=r-l;
                if(r-l<ansLen){
                    ansLen=r-l;
                    ansInd=l;
                }
                ump[s[l]]++;
                if(ump[s[l]]>0) currChars--;
                l++;
            }
        }
        if(ansLen==1e9) return "";
        return s.substr(ansInd,ansLen);
    }
};