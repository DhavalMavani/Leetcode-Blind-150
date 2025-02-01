class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref=strs[0];
        int n=strs.size(), len=pref.size();
        for(int i=1;i<n;i++){
            
            while(len> strs[i].size()) len--;

            while(len-1>=0 && pref.substr(0,len) != strs[i].substr(0,len) ) len--;
            if(len==0) return "";

            pref=pref.substr(0,len);

        }
        return pref;
    }
};