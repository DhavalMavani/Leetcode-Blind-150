class Solution {
public:
    static bool comp(pair<int,string> &p1,pair<int,string> &p2){
        if(p1.first!=p2.first) return p1.first>p2.first;
        else return p1.second<p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int>ump;
        for(auto &i: words) ump[i]++;

        vector<pair<int,string>> arr;
        for(auto &i: ump) arr.push_back({i.second,i.first});

        sort(arr.begin(),arr.end(),comp);

        for(int i=0;i<k;i++) ans.emplace_back(arr[i].second);

        return ans;
    }
};