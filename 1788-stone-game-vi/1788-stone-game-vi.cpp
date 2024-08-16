class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size(),alice=0,bob=0;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) arr.push_back({aliceValues[i]+bobValues[i],i});
        sort(arr.begin(),arr.end(),greater<>());

        for(int i=0;i<n;i++){
            if(i%2) bob+=bobValues[arr[i].second];
            else alice+=aliceValues[arr[i].second];
        }
        arr.clear();
        if(alice>bob) return 1;
        else if(alice<bob) return -1;
        return 0;
    }
};