class RandomizedSet {
public:
    unordered_map<int,int> ump;
    vector<int> arr;
    int n=0;

    bool insert(int val) {
        if(ump.count(val)) return false;
        arr.emplace_back(val);
        ump[val]=n;
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(!ump.count(val)) return false;
        int ind=ump[val];
        ump.erase(val);
        n--;
        if(ind!=arr.size()-1){
            swap(arr[ind],arr[n]);
            ump[arr[ind]]=ind;
        }
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */