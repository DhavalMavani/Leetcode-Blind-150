class Solution {
public:
    static bool comp(vector<int> &p1, vector<int> &p2){
        return p1[1]<p2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        
        int n=intervals.size(),lastEndTime=intervals[0][1], longest=1;

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastEndTime){
                lastEndTime=intervals[i][1];
                longest++;
            }
        }
        return n-longest;
    }
};