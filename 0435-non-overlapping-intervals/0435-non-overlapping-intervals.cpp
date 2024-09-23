class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int temp=intervals[0][1],n=intervals.size(),ans=0,i=1;

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=temp ) temp = intervals[i][1] ;
            else{
                temp= min( temp, intervals[i][1]) ;
                ans++;
            }
        }
        return ans;
    }
};