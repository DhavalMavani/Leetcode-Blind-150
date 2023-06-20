class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0,l=0,r=height.size()-1;
        while(l<r){
            int area=(r-l)*(min(height[l],height[r]));
            maxA=max(area,maxA);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxA;
    }
};