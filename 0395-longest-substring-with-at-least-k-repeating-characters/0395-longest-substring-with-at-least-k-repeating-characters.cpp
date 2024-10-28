class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        int i = 0;
        while (i < s.size() && freq[s[i]] >= k) i++;
        
        if (i == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0, i), k);
        while (i < s.size() && freq[s[i]] < k) i++;
        int right = longestSubstring(s.substr(i), k);
        
        return max(left, right);
    }
};