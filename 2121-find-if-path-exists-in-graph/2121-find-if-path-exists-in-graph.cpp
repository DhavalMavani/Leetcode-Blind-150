class Solution {
public:
    int find(int a[], int x) {
        if (x != a[x]) a[x] = find(a, a[x]);
        return a[x];
    }

    void unionf(int a[], int x, int z) {
        a[find(a, z)] = find(a, x);
    }

    bool connected(int a[], int x, int z) {
        return find(a, x) == find(a, z);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // unordered_map<int, vector<int>> mp
        int p[n];
        for (int i = 0; i < n; i++) p[i] = i;
        for (auto& i : edges) {
            unionf(p, i[0], i[1]);
        }
        return connected(p, source, destination);
    }
};