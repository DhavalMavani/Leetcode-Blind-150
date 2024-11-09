class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> medians;
        unordered_map<int,int> mp; 
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i=0;i<k;i++) maxh.push(nums[i]);

        for(int i=0;i<(k/2);i++) minh.push(maxh.top()),maxh.pop();

        for(int i=k;i<n;i++) {
            if(k&1) medians.push_back(maxh.top()*1.0);
            else medians.push_back(((double)maxh.top()+(double)minh.top())/2);

            int p=nums[i-k], q=nums[i], balance = 0; 

            if(p<=maxh.top()) {
                balance--;
                if(p==maxh.top()) maxh.pop();
                else mp[p]++;
            }
            else {
                balance++;
                if(p == minh.top()) minh.pop();
                else mp[p]++;
            }
            
            if(!maxh.empty() and q<=maxh.top()) maxh.push(q),balance++;
            else minh.push(q),balance--;
            
            if(balance<0) maxh.push(minh.top()), minh.pop();
            else if(balance>0) minh.push(maxh.top()),maxh.pop();
            
            while(!maxh.empty() and mp[maxh.top()]) mp[maxh.top()]--,maxh.pop();

            while(!minh.empty() and mp[minh.top()]) mp[minh.top()]--,minh.pop();
        }

        if(k&1) medians.push_back(maxh.top()*1.0);
        else medians.push_back(((double)maxh.top()+(double)minh.top())/2.0);

        return medians;
    }
};