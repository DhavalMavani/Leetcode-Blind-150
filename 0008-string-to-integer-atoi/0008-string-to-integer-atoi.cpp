class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();

        while(i<n && s[i]==' ') i++;
        bool sign=true;

        if(s[i]=='+') i++;
        else if(s[i]=='-'){
            sign=false;
            i++;
        }

        while(i<n && s[i]=='0') i++;

        int str=i;
        long long ans=0;
        while(i<n && isdigit(s[i]) ){
            ans=ans*10 + s[i]-'0';
            if(ans>INT_MAX){
                if(sign) return INT_MAX;
                else return INT_MIN;
            }
            else if(ans<INT_MIN) {
                if(sign) return INT_MIN;
                else return INT_MAX;
            } 
            i++;
        }
        if(str==i) return 0;
        if(sign) return ans;
        return -ans;
    }
};

// isdigit()