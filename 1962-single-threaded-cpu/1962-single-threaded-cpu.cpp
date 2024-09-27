class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size(), ind=0;
        long long currTime=0;
        for(int i=0;i<n;i++) tasks[i].emplace_back(i);
        sort(tasks.begin(),tasks.end());
        
        vector<int> ans;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        while(ans.size()!=n){
            if(pq.empty()) currTime=max (currTime,(long long)tasks[ind][0]);

            while(ind<n && tasks[ind][0]<=currTime){
                pq.push({tasks[ind][1],tasks[ind][2]});
                ind++;
            }

            currTime+=pq.top().first;
            ans.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};