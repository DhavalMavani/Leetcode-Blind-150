class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int temp=intervals[0][1],n=intervals.size(),ans=0,i=1;

        while(i<n){
            if(intervals[i][0]>=temp ) temp = intervals[i][1] ;
            else{
                temp= min( temp, intervals[i][1]) ;
                ans++;
            }
            i++;
        }
        return ans;
    }
};