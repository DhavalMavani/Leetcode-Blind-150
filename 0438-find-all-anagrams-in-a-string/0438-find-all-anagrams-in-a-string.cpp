class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l=0,r=0,n=s.size(), len=p.size(),match=0;

        if(len>n) return {};

        vector<int> freqP(26,0);
        vector<int> freqS(26,0);
        
        for(int i=0;i<len;i++) freqP[p[i]-'a']++;
        for(int i=0;i<len-1;i++) freqS[s[i]-'a']++;

        for(int i=0;i<26;i++) match+=min(freqS[i],freqP[i]);

        vector<int> ans;

        for(int i=len-1;i<n;i++){
            int currChar=s[i]-'a', prevChar=s[i-len+1]-'a';
            if(freqS[currChar]<freqP[currChar]) match++;
            freqS[currChar]++;

            if(match==len) ans.emplace_back(i-len+1);

            if( freqS[prevChar]<=freqP[prevChar]) match--;
            freqS[prevChar]--;
        }
        return ans;
    }
};