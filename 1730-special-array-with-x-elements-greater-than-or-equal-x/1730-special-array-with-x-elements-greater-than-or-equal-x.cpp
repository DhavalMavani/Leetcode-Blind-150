class Solution {
public:
    int specialArray(vector<int>& num) {
        sort(num.begin(),num.end());
        int n=num.size();
        for(int i=0;i<n;i++){
            int s=n-i;
            if(num[i]>=s && (i==0 || num[i-1]<s )) return s;
        }
        return -1;        
    }
};