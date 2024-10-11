class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),ind=0;
        string ans;
        while(ind<n){
            if(s[ind]==' ') ind++;
            else{
                int r=ind;
                while(r<n && s[r]!=' ') r++;
                if(ans.empty()) ans=s.substr(ind,r-ind);
                else ans=s.substr(ind,r-ind)+' '+ans;
                ind=r+1;
            }
        }
        return ans;
    }
};