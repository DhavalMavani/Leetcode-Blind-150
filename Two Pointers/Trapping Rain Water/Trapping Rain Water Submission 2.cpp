class Solution {
public:
    int trap(vector<int>& height) {
        int maxl=height[0],maxr=height[height.size()-1],l=0,r=height.size()-1,ans=0;
        while(l<r){
            if(maxl<maxr){
                l++;
                maxl=max(maxl,height[l]);
                if(min(maxl,maxr)-height[l]>0){
                    ans+=min(maxl,maxr)-height[l];
                }
            }
            else {
                r--;
                maxr=max(maxr,height[r]);
                if(min(maxl,maxr)-height[r]>0){
                    ans+=min(maxl,maxr)-height[r];
                }
            }
        }
        return ans;
    }
};