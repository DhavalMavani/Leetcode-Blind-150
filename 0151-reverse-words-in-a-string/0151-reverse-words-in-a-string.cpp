class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),ind=0,l=0,r=0;
        
        reverse(s.begin(),s.end());
        while(ind < n){
            while (ind<n && s[ind]==' ') ind++;
            
            while(ind<n && s[ind]!=' '){
                s[r]=s[ind];
                ind++;
                r++;
            }
            s[r]=' ';
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                r++;
                l=r;
            }
        }
        return s.substr(0,r-1);
    }
};