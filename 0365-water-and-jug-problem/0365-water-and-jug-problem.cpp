class Solution
{
public:
    bool dfs(int x, int y, int z, int m, int curr, vector<int> &vis)
    {
        if (curr < 0 || curr > m || vis[curr] == 1) return false;
        if (curr == z) return true;
        vis[curr] = 1;
        return dfs(x, y, z, m, curr + x, vis) || dfs(x, y, z, m, curr - x, vis) ||
        dfs(x, y, z, m, curr + y, vis) || dfs(x, y, z, m, curr - y, vis);
    }
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y == z || x == z || y == z) return true;
        if (x + y < z) return false;
        int m = x + y; // max capacity
        vector<int> vis(m + 1, 0);
        return dfs(x, y, z, m, 0, vis);
    }
};