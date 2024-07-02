class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int offset[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        int steps = 1;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int a = x + offset[j], b = y + offset[j + 1];

                    if (a >= 0 && b >= 0 && a < m && b < n && ans[a][b] == -1) {
                        ans[a][b] = steps;
                        q.emplace(a, b);
                    }
                }
            }
            steps++;
        }
        return ans;
    }
};