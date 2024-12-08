class Solution {
public:
    typedef pair<double,pair<int,int>> fraction;
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<fraction, vector<fraction>, greater<fraction>> pq;
        
        for(int i = 0; i < n; i++) pq.push({1.0*arr[i]/arr[n-1], {i,n-1} });
        
        
        while(k-- !=1) {

            fraction f = pq.top();
            pq.pop();
            
            int i = f.second.first;
            int j = f.second.second-1;
            
            pq.push({1.0*arr[i]/arr[j], {i,j} });
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};