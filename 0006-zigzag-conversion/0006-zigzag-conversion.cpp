class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        int gap=2*(numRows-1), len=s.size();

        if(!gap) return s;

        for(int i=0;i<numRows;i++){
            for(int j=i;j<len ;j=j+gap){

                ans+=s[j];
                if(i!=0 && i!=numRows-1 && j+ (gap-2*i) <len){
                    ans+=s[j+gap-2*i];
                }
            }
        }

        return ans;
    }
};