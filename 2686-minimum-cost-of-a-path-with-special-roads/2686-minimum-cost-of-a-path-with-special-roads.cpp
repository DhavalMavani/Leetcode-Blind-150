class Solution {
public:
    static int calcDist(int &x1, int &y1, int &x2, int &y2) {
        return abs(x1-x2)+abs(y1-y2);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n=specialRoads.size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<int> distToSpecialRoad(n+1,INT_MAX);
        pq.push({0,{start[0],start[1]}});
        while(!pq.empty()){
            int dist=pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
            pq.pop();
            if(x==target[0] && y==target[1]) return dist;

            int d=dist+calcDist(x,y,target[0],target[1]);
            if(d<distToSpecialRoad[n]){
                distToSpecialRoad[n]=d;
                pq.push({d,{target[0],target[1]} } );
            }

            for(int i=0;i<n;i++){
                d=dist+calcDist(x,y,specialRoads[i][0],specialRoads[i][1]) + specialRoads[i][4];
                if(d<distToSpecialRoad[i]){
                    distToSpecialRoad[i]=d;
                    pq.push({distToSpecialRoad[i],{specialRoads[i][2],specialRoads[i][3]} } );
                }
            }
        }
        return 0;
    }
};