class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());

        ans.emplace_back(intervals[0]);
        
        int i=1;
        while(i<n){
            if(intervals[i][0]>ans[ans.size()-1][1] ){
                ans.emplace_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1], intervals[i][1]) ;
            }
            i++;
        }
        return ans;
    }
};