class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,-1);

        for(int i=0;i<=n;i++){
            if(ranges[i]==0) continue;
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            startEnd[l]=max(startEnd[l],r);
        }
        int l=0,r=startEnd[0],ans=0;
        while(l<n+1){
            int temp=r;
            for(int i=l;i<=temp;i++){
                r=max(r,startEnd[i]);
            } 
            if(r<l) return -1;
            l=temp+1;
            ans++;
        }
        return ans;
    }
};