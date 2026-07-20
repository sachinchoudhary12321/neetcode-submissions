class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        // Push all gates into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            pair<int, int> p = q.front().first;
            int time = q.front().second;
            q.pop();

            int x = p.first;
            int y = p.second;

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    grid[nx][ny] == INT_MAX) {

                    grid[nx][ny] = time + 1;
                    q.push({{nx, ny}, time + 1});
                }
            }
        }
    }
};