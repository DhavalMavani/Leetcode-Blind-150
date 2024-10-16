class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        bool exponent=false, decimal=false;
        for(int i=0;i<n;i++){
            cout<<s[i]<<" ";
            if(s[i]=='E' || s[i]=='e'){
                if(exponent || i==n-1 || i==0) return false;
                else if(s[i-1]=='.'){
                    if(s[i-2]<0 || int(s[i-2])<48 || int(s[i-2])>57) return false;
                }
                else if(int(s[i-1])<48 || int(s[i-1])>57 ) return false;
                exponent=true;
            }
            else if(s[i]=='+' || s[i]=='-'){
                if(i>0){
                    cout<<s[i-1]<<" ";
                    if(s[i-1]!='E' && s[i-1]!='e'){
                        cout<<"fty";
                        return false;
                    }
                }
                if(i==n-1) return false;
            }

            else if(s[i]=='.'){
                if(decimal || exponent ) return false;
                else if(i>0){
                    if (i==n-1){
                        if(int(s[i-1])<48 || int(s[i-1])>57 ) return false;
                    }
                }
                else if(i==0 ){
                    if(i==n-1)return false;
                    else if(int(s[i+1])<48 || int(s[i+1])>57) return false;
                }
                decimal=true;
            }
            else if(int(s[i])<48 || int(s[i])>57) return false;
        }
        return true;
    }
};

        // cout<<int('0')<<" "<<int('9');
// 0->48 9->57