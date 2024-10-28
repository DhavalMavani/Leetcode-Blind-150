class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        
        vector<int> freq(26);
        for (char &c : s) freq[c-'a']++;
        
        int i = 0;
        while (i < s.size() && freq[s[i]-'a'] >= k) i++;

        if (i == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0, i), k);
        while (i < s.size() && freq[s[i]-'a'] < k) i++;
        int right = longestSubstring(s.substr(i), k);
        
        return max(left, right);
    }
};