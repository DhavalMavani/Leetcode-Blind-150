class Solution {
public:
    int calcDist(int &x1, int &y1, int &x2, int &y2) {
        if (x1 == x2) return abs(y2 - y1);
        else return abs(x2 - x1);
    }
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size(),ans=INT_MAX;
        unordered_map<int,unordered_set<int>> st;

        for(int i=0;i<n;i++) st[points[i][0]].emplace(points[i][1]);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                if(x1==x2 || y1==y2) continue;

                int p1x=points[i][0], p1y = points[j][1], p2x= points[j][0] ,p2y = points[i][1];

                if(st[p1x].count(p1y) && st[p2x].count(p2y)){
                    ans=min(ans,calcDist(x1,y1,p1x,p1y)*calcDist(x1,y1,p2x,p2y));
                }
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};