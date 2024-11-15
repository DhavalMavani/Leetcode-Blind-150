class Solution {
public:
    unordered_set<string> visited;
    string ans;
    int n,k;
    bool dfs() {
        if(visited.size() == pow(k, n)) return true;
        
        string suffix = ans.substr(ans.size() - (n-1), n-1);
        string nextNode = suffix + '0';
        for(int i = 0; i < k; i++) {
            nextNode[n-1] = (i + '0');
                
            if(!visited.count(nextNode)) {
                visited.insert(nextNode);
                ans += (i + '0');
                
                // hamiltonian path found
                if(dfs()) return true;

                visited.erase(nextNode);
                ans.pop_back();
            }
        }
        
        return false;
    }
    
    string crackSafe(int N, int K) {
        n=N,k=K;
        ans = string(n, '0');
        visited.insert(ans);
        dfs();
        return ans;
    }
};
