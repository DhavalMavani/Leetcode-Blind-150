class Solution {
public:
    int b,lad;
    bool isPossible(vector<int> &heights,int mid){
        vector<int> h;
        for(int i=1;i<=mid;i++) if(heights[i]>heights[i-1]) h.emplace_back(heights[i]-heights[i-1]);
        sort(h.begin(),h.end());
        int n=h.size()-1,sum=0;
        for(int i=0;i<=n-lad;i++){
            sum+=h[i];
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