class Solution {
public:
    int b,lad;
    bool isPossible(vector<int> &heights,int mid){

        priority_queue<int> pq;
        for(int i=1;i<=mid;i++) if(heights[i]>heights[i-1]) pq.emplace(heights[i]-heights[i-1]);
        for(int i=0;i<lad && !pq.empty();i++) pq.pop();
        
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
            if(sum>b) return false;
        }
        
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l=0,r=heights.size()-1;
        b=bricks,lad=ladders;
        while(l<=r){
            int mid=(l+r)/2;
            if(isPossible(heights,mid)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};