class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainder(60,0);

        for(auto &i: time) remainder[i%60]++;
        long ans=0;
        for(int i=0;i<60;i++){
            if(i==30 || i==0) ans+=(long) remainder[i]*(remainder[i]-1);
            else ans+=(long) remainder[i]*remainder[60-i];
        }
        return ans/2;
    }
};