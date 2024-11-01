class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue< int , vector<int>, greater<int> >pq;
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                if(pq.size()<ladders) pq.emplace(heights[i]-heights[i-1]);
                else if(!pq.empty() && pq.top()<heights[i]-heights[i-1]){
                            bricks-=pq.top();
                            if(bricks<0) return i-1;
                            pq.pop();
                            pq.emplace(heights[i]-heights[i-1]);
                }
                else{
                    bricks-=heights[i]-heights[i-1];
                    if(bricks<0) return i-1;
                }
            }
        }
        return n-1;
    }
};