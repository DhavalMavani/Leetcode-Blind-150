class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> ump;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) ump[arr[i]].emplace_back(i);
    }
    
    int query(int left, int right, int value) {
        return upper_bound(ump[value].begin(),ump[value].end(),right ) - lower_bound(ump[value].begin(),ump[value].end(),left );
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */