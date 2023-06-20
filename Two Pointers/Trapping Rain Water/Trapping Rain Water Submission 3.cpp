class Solution {
public:
    int trap(vector<int>& height) {
        int s=height.size(),ans=0;
        vector <int> maxL(s),maxR(s);

        for(int i=0;i<s;i++){
            if(i==0){
                maxL[i]=0;
            }
            else{
            maxL[i]= max(height[i-1],maxL[i-1]);
            }
        }

        for(int i=s-1;i>=0;i--){
            if(i==s-1){
                maxR[i]=0;
            }
            else{
            maxR[i]= max(height[i+1],maxR[i+1]);
            }
        }

        for(int i=0;i<s;i++){
            int a=min(maxL[i],maxR[i]);    
            if(a-height[i]>0){
                ans += (a-height[i]);
            }
        }

        return ans;
    }
};