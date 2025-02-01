class Solution {
public:
    void palindrome(string &s, int l,int r, pair<int,int> &ansIndex){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l>ansIndex.second-ansIndex.first) ansIndex={l,r};
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        pair<int,int> ansIndex={0,0};
        for(int i=0;i<s.size();i++){
            palindrome(s,i,i,ansIndex);
            palindrome(s,i,i+1,ansIndex);
        }
        return s.substr(ansIndex.first,ansIndex.second-ansIndex.first+1);
    }
};