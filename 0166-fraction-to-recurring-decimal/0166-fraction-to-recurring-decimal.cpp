class Solution {
public:
    // n=numerator
    // d=denominator
    string fractionToDecimal(long n, long d) {
        string ans;
        if( (n<0 && d>0) || (n>0 && d<0) ){
            ans+='-';
            n*=-1;
        }
        ans+=to_string(n/d);
        n=n%d;
        if(n==0) return ans;
        ans+='.';

        unordered_map<int,int> ump;
        string s2;
        int i=0;
        while(n && !ump.count(n) ){
            ump[n]=i;
            n=n*10;
            s2+=to_string(n/d);
            if(n/d!=0) n%=d;
            i++;
        }
        if(n==0) return ans+s2;
        return ans+ s2.substr(0,ump[n]) + '('+s2.substr(ump[n] )+')';
    }
};