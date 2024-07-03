#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        queue<tuple<int, int, int>> q;
        int dirs[] = {0, 1, 0, -1, 0};
        q.push({0, 0, k}); 
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        visited[0][0][k] = true; 
        
        int dist = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto [x, y, currK] = q.front();
                q.pop();
                
                if (x == m - 1 && y == n - 1) return dist;
                
                for (int j = 0; j < 4; j++) {
                    int a = x + dirs[j], b = y + dirs[j + 1];
                    if (a >= 0 && b >= 0 && a < m && b < n) {
                        int newK = currK - grid[a][b];
                        if (newK >= 0 && !visited[a][b][newK]) {
                            visited[a][b][newK] = true;
                            q.push({a, b, newK});
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
