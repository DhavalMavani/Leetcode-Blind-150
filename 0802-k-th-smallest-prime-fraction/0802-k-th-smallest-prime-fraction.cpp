class Solution {
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>> > pq;
        
        for(int i = 0; i < n; i++) pq.push({1.0*arr[i]/arr[n-1], 1.0*i,1.0*(n-1) });
        
        
        while(k-- !=1) {

            vector<double> v = pq.top();
            pq.pop();
            
            int i = v[1], j=v[2]-1;
            
            pq.push({1.0*arr[i]/arr[j], 1.0*i,1.0*j });
        }
        
        return {arr[pq.top()[1]], arr[pq.top()[2]]};
    }
};