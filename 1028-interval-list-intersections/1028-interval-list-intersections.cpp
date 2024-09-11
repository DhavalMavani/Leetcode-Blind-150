class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fSize=firstList.size(), sSize=secondList.size(), p1=0,p2=0;
        
        vector<vector<int>> ans;

        while(p1<fSize && p2<sSize){
            int str=max(firstList[p1][0],secondList[p2][0]);
            int end=min(firstList[p1][1],secondList[p2][1]);

            if( str<=end) ans.push_back({str,end});

            if(firstList[p1][1]>secondList[p2][1]) p2++;
            else p1++;
        }
        return ans;
    }
};