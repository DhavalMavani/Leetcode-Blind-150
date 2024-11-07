class Solution {

double calcPow(double x,int n){
    if(n==0) return 1;

    double ans=calcPow(x,n/2);

    if(n%2==0) return ans*ans;
    else return ans*ans*x;
}

public:
    double myPow(double x, int n) {
        if(x==0) return 0;

        if(n>=0) return calcPow(x,n);
        else return 1/calcPow(x,abs(n));
    }
};