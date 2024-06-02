class Solution {
public:
    int minimumChairs(string s) {
        int ans=0,chair=0;
        for(auto &i: s){
            if(i=='E') chair++;
            else chair--;
            ans=max(ans,chair);
        }
        
        return ans;
    }
};