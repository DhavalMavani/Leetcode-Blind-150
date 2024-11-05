#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int a) {
        if (a == parent[a]) return a;
        return parent[a] = findParent(parent[a]);
    }

    void unionSets(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);
        if (rootA == rootB) return;

        if (size[rootA] >= size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }
};

class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r;
        long long result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return static_cast<int>(result);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), ans = n;
        DisjointSet dsu(n);
        
        vector<vector<int>> adj(n);
        map<int, vector<int>> valueGroups;

        for (auto& edge : edges) {
            int e1 = edge[0], e2 = edge[1];
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
        }
        for (int i = 0; i < n; i++) valueGroups[vals[i]].push_back(i);
        
        vector<bool> active(n, false);
        for (auto& [val, nodes] : valueGroups) {
            for (int node : nodes) {
                active[node] = true;
                for (int &neighbor : adj[node]) {
                    if (active[neighbor] && vals[neighbor] <= val) dsu.unionSets(neighbor, node);
                }
            }
            
            unordered_map<int, int> componentSize;
            for (int &node :nodes) {
                int root = dsu.findParent(node);
                componentSize[root]++;
            }
            
            for (auto& [root, size] : componentSize) if (size >= 2) ans += nCr(size, 2);
        }
        
        return ans;
    }
};
