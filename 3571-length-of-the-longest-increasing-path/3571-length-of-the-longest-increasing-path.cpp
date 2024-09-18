class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int lis(vector<int> &arr){
        if(arr.size()==0) return 0;
        int n=arr.size();
        vector<int> temp;
        temp.emplace_back(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()) temp.emplace_back(arr[i]);
            else *lower_bound(temp.begin(),temp.end(),arr[i])=arr[i];
        }
        return temp.size();
    }
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int x=coordinates[k][0], y=coordinates[k][1];
        sort(coordinates.begin(),coordinates.end(),comp);

        vector<int> less, more;
        for(auto &i: coordinates){
            if(i[0]<x && i[1]<y) less.emplace_back(i[1]);
            else if(i[0]>x && i[1]>y) more.emplace_back(i[1]);
        }

        int l=lis(less);
        int r=lis(more);
        return l+r+1;
    }
};