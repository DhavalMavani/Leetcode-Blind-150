class Solution {
public:
    int K;
    string str;
    int helper(int l,int r){

        if(l>=r) return 0;

        vector<int> freq(26,0);

        for(int i=l;i<=r;i++) freq[str[i]-'a']++;

        for(int i=l;i<=r;i++) if(freq[str[i]-'a']<K) return max(helper(l,i-1),helper(i+1,r));

        return r-l+1;

    }
    int longestSubstring(string s, int k) {
        if(k==1) return s.size();
        K=k;
        str=s;
        return helper(0,s.size()-1);
    }
};