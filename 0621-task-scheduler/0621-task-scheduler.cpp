class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &i: tasks) freq[i-'A']++;

        int time=0;
        priority_queue<int> pq;
        for(int i=0;i<26;i++) if(freq[i]!=0) pq.push(freq[i]);
        
        while(!pq.empty()){
            vector<int> temp;
            int i=0;
            for(;i<=n && !pq.empty();i++){
                int curr=pq.top();
                pq.pop();
                if(curr-1>0)temp.emplace_back(curr-1);
            }

            if(!temp.empty()) time+=n+1;
            else time+=i;

            for(auto &i: temp) pq.push(i);
        }
        return time;
    }
};