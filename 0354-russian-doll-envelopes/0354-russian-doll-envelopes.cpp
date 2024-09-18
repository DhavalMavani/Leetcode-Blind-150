class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        int n=envelopes.size();
        vector<int> temp;
        temp.emplace_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(temp.back()<envelopes[i][1]) temp.emplace_back(envelopes[i][1]);
            else *lower_bound(temp.begin(),temp.end(),envelopes[i][1])= envelopes[i][1];
        }
        return temp.size();
    }
};