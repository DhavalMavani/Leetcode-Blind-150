class Solution {
public:
    long long calculateScore(string s) {
        long long total=0,n=s.size();
        unordered_map<int,stack<int>> ump;

        for(int i=0;i<n;i++){
            int curr=s[i]-'a', rev=25-curr;
            if(!ump[rev].empty()){
                total+= i-ump[rev].top();
                ump[rev].pop();
            }
            else ump[curr].push(i);
        }

        return total;
    }
};