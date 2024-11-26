class LockingTree {
public:
    vector<vector<int>> adj;
    vector<int> lockArr;
    vector<int> parentArr;
    LockingTree(vector<int>& parent) {
        int n=parent.size();
        adj.resize(n);
        parentArr.resize(n);
        parentArr[0]=-1;
        lockArr.resize(n,-1);
        for(int i=1;i<n;i++){
            parentArr[i]=parent[i];
            adj[parent[i]].emplace_back(i);
        } 
    }
    
    bool lock(int num, int user) {
        if(lockArr[num]==-1){
            lockArr[num]=user;
            return true;
        } 
        return false;
    }
    
    bool unlock(int num, int user) {
        if(lockArr[num]==user){
            lockArr[num]=-1;
            return true;
        } 
        return false;       
    }
    
    bool upgrade(int num, int user) {
        if(lockArr[num]!=-1) return false;

        bool checkDescendant= dfs(num);
        if(!checkDescendant) return false;

        bool ancestorsLocked=checkParent(num);
        if(ancestorsLocked) return false;

        unlockDfs(num);
        lockArr[num]=user;

        return true;
    }

    void unlockDfs(int &node){
        lockArr[node]=-1;
        for(auto &i: adj[node]) unlockDfs(i);
    }

    bool checkParent(int &curr){
        if(curr==-1) return false;
        if(lockArr[curr]!=-1) return true;

        return checkParent(parentArr[curr]);
    }

    bool dfs(int &num){
        if(lockArr[num]!=-1) return true;
        for(auto &i: adj[num]) if( dfs(i) ) return true;
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */