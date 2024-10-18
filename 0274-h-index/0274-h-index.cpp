class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size(),l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if( citations[mid]<=n-mid ) l=mid+1;
            else r=mid-1;        
        }
        if(r==-1) return n;
        int ans=citations[r];
        if(r+1<n) ans=max(ans,min(n-(r+1),citations[r+1]) );
        return ans;
    }
};