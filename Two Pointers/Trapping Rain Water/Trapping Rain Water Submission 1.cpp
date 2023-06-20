class Solution {
public:
    int trap(vector<int>& height) {

        int maxl=height[0],maxr=height[height.size()-1],l=0,r=height.size()-1,ans=0;

        while(l<r){

            
            if(maxl<=maxr){
                l++;
                maxl=max(maxl,height[l]);
                    ans+=maxl-height[l];
            }
            else {
                r--;
                maxr=max(maxr,height[r]);
                ans+=maxr-height[r];
            }

        }

        return ans;
    }
};