class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1);

        for(int i=0;i<=n;i++){
            if(ranges[i]==0) continue;
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            startEnd[l]=max(startEnd[l],r);
        }

        int l=1,r=startEnd[0],ans=1;
        while(r<n){
            int temp=r;
            for(int i=l;i<=temp;i++) r=max(r,startEnd[i]);
            if(r==temp) return -1;
            l=temp+1;
            ans++;
        }
        return ans;
    }
};