class RandomizedSet {
public:

    unordered_map<int,int> mp;
    vector<int> v1;
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        v1.emplace_back(val);
        mp[val]=v1.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int temp=mp[val];
            int n=v1.size();
            mp[v1[n-1]]=temp;
            swap(v1[temp],v1[n-1]);
            v1.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v1[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */