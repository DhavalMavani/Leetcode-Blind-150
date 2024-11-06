class Solution
{
public:
    int j1,j2,t;
    bool dfs(int curr, vector<bool> &vis)
    {
        if (curr < 0 || curr > j1+j2 || vis[curr] ) return false;
        if (curr == t) return true;
        vis[curr] = 1;
        return dfs(curr+j1,vis) || dfs(curr+j2,vis) || dfs(curr-j1,vis) || dfs(curr-j2,vis);
    }
    bool canMeasureWater(int x, int y, int target)
    {
        j1=x,j2=y,t=target;
        if (j1+j2 < t) return false;
        if (j1+j2 == t || j1 == t || j2 == t) return true;
        vector<bool> vis( j1+j2+1, false);
        return dfs(0,vis);
    }
};