class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fSize=firstList.size(), sSize=secondList.size(), p1=0,p2=0;
        
        vector<vector<int>> ans;

        while(p1<fSize && p2<sSize){
            int s1=firstList[p1][0], e1= firstList[p1][1], s2= secondList[p2][0], e2=secondList[p2][1];

            if(max(s1,s2)<=min(e1,e2) ){

                int str=max(s1,s2);
                int end=min(e1,e2);

                ans.push_back({str,end});

                if(e1<e2) p1++;
                else p2++;
            }
            else if(e2>e1) p1++;
            else p2++;
        }
        return ans;
    }
};