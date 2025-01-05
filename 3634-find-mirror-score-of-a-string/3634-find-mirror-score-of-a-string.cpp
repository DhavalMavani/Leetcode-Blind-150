class Solution {
public:
    long long calculateScore(string s) {
        long long total=0,n=s.size();
        vector<vector<int>> ump(26);

        for(int i=0;i<n;i++){
            int curr=s[i]-'a', rev=25-curr;
            if(!ump[rev].empty()){
                total+= i-ump[rev].back();
                ump[rev].pop_back();
            }
            else ump[curr].emplace_back(i);
        }

        return total;
    }
};