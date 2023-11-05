class Solution {
public:
    int nthUglyNumber(int n) {

        int p_2=0;
        int p_3=0;
        int p_5=0;

        vector<int> UglyNumber(n,1);

        for(int i=1;i<n;i++){
            int twoMultiple=2*UglyNumber[p_2];
            int threeMultiple=3*UglyNumber[p_3];
            int fiveMultiple=5*UglyNumber[p_5];

            UglyNumber[i]=min(twoMultiple,min(threeMultiple,fiveMultiple));
            
            if(UglyNumber[i]==twoMultiple) p_2++;
            if(UglyNumber[i]==threeMultiple) p_3++;
            if(UglyNumber[i]==fiveMultiple) p_5++;
        }

        return UglyNumber[n-1];
    }
};