class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ccount[26] = {0};
        int i=0,j=0;
        int count = 0, n = s.size();

        while(j<n) {
            int c=s[j]-'a';
            ccount[c]++;
            while(ccount[c]>=k) {
                count += n-j;
                ccount[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};