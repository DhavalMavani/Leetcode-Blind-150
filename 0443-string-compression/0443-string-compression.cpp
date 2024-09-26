class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size(),ind=0,r=0;

        for(int i=0;i<n;i++){
            char c=chars[i];
            r=i;
            while(r+1<n && chars[i]==chars[r+1]) r++;
            chars[ind]=c;
            ind++;
            if(r-i>0){
                string num=to_string(r-i+1);
                for(auto &j: num){
                    chars[ind]=j;
                    ind++;
                }
            }
            i=r;
        }
        return ind;
    }
};