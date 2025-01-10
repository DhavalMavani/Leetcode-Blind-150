class RandomizedSet {
public:

    unordered_set<int> ust;
    // vector<int> 
    bool insert(int val) {
        if(ust.count(val)) return false;
        ust.emplace(val);
        return true;
    }
    
    bool remove(int val) {
        if(ust.count(val)){
            ust.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // return *ust.begin();
        return *next(ust.begin(),rand()%ust.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */