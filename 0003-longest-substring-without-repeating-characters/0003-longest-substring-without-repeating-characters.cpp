class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l=0,maxSubstring=0,n=s.size();
        unordered_set <char> st;

        for(int r=0;r<n;r++){

            while( st.count( s[r] )  ){
                st.erase( s[l] );
                l++;
            }
            st.emplace(s[r]);
            maxSubstring = max(maxSubstring,r-l+1);
        }
        return maxSubstring;
    }
};