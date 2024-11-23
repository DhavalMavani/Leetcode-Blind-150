// -1 not visited
// 0 prime
// 1 not prime

class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n,-1);

        for(int i=2;i<n;i++){
            if(arr[i]==-1){
                arr[i]=0;
                for(int j=i+i;j<n;j+=i) arr[j]=1;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++) if(!arr[i]) ans++;

        return ans;
    }
};