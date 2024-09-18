class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        int n=envelopes.size(),ans=0;
        vector<int> temp(n+1,INT_MAX);
        for(int i=0;i<n;i++) *lower_bound(temp.begin(),temp.end(),envelopes[i][1])= envelopes[i][1];
        for(int i=0;i<n;i++){
            if(temp[i]==INT_MAX) break;
            ans++;
        }
        return ans;
    }
};