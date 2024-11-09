class Solution {
public:
    long long minEnd(int n, int x) {
        vector<bool> xBinary(64,0);
        vector<bool> nBinary(32,0);

        for(int i=0;i<32;i++){
            if(x==0) break;
            if(x&1) xBinary[i]=1;
            x=x>>1;
        }
        n--;
        for(int i=0;i<32;i++){
            if(n==0) break;
            if(n&1) nBinary[i]=1;
            n=n>>1;
        }
        int xPtr=0,nPtr=0;
        while(nPtr<32){
            while(xBinary[xPtr]) xPtr++;
            xBinary[xPtr]=nBinary[nPtr];
            xPtr++;
            nPtr++;
        }
        long long ans=0;
        for(int i=0;i<64;i++) if(xBinary[i]) ans+=(long long)1<<i;
        return ans;
    }
};