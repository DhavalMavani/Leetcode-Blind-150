class Solution {
public:
    bool isPossible(vector<int>& start, int &d, long long &mid){
        long long n=start.size(),prev=start[0];

        for(int i=1;i<n;i++){
            if(start[i] + d - prev  >= mid){
                prev=max(prev+mid,(long long)start[i]);
            }
            else return false;
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());

        long long l=0,r=start.back() - start.front() + d;

        while(l<=r){
            long long mid=(l+r)/2;

            if(isPossible(start,d,mid)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};