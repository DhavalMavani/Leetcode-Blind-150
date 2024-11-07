class Solution {
public:
    int mySqrt(int x) {
        int l=1,r=x;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((long long)mid*mid>x) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};