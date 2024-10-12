class Solution {
public:
    string frequencySort(string s) {
        string ans;
        vector<int> freq(75,0);
        for(auto &i: s) freq[i-'0']++;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<75;i++) if(freq[i]!=0)pq.push({freq[i],i});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            ans.append(t.first,'0'+t.second);
        }
        return ans;
    }
};