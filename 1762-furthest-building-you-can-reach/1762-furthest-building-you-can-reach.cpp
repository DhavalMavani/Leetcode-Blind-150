class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> pq;
        
        for(int i=1;i<n;i++){
            int diff=heights[i-1]-heights[i];
            if(diff<0){
                pq.emplace(diff);
                if(pq.size()>ladders){
                    bricks+=pq.top();
                    pq.pop();
                }
                if(bricks<0) return i-1;
            }
        }
        return n-1;
    }
};