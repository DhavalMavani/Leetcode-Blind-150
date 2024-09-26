class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        vector<char> ans;

        for(int i=0;i<n;i++){
            int r=i;
            while(r+1<n && chars[i]==chars[r+1]) r++;
            ans.emplace_back(chars[i]);
            if(r-i>0){
                string num=to_string(r-i+1);
                for(auto &j: num) ans.emplace_back(j);
            }
            i=r;
        }
        chars=ans;
        return ans.size();
    }
};