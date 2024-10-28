class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())return {newInterval};
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++ ){
            int s1=intervals[i][0],e1=intervals[i][1];

            if(newInterval[1]< s1 ){
                ans.emplace_back(newInterval);
                while(i<n){
                    ans.emplace_back(intervals[i]);
                    i++;
                }
                return ans;
            } 
            else if(newInterval[0]>e1 ) ans.emplace_back(intervals[i]);
            else {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.emplace_back(newInterval);
        return ans;
    }
};