class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue< int >pq;
        for(int i=1;i<n;i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                if(pq.size()<ladders) pq.emplace(-diff);
                else if(!pq.empty() && (-pq.top()) < diff){
                    bricks+=pq.top();
                    pq.pop();
                    pq.emplace(-diff);
                }
                else bricks-=diff;

                if(bricks<0) return i-1;
            }
        }
        return n-1;
    }
};