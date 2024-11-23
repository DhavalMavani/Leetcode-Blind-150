// -1 not visited
// 0 prime
// 1 not prime

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n);
        int ans=0;

        for(int i=2;i<n;i++){
            if(!arr[i]){
                ans++;
                for(int j=i;j<n;j+=i) arr[j]=1;
            }
        }

        return ans;
    }
};