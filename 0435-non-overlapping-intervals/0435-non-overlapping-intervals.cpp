class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int endTime=intervals[0][1],n=intervals.size(),ans=0;

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=endTime ) endTime = intervals[i][1];
            else{
                endTime = min( endTime, intervals[i][1]) ;
                ans++;
            }
        }
        return ans;
    }
};