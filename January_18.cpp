class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int totalWater = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        while (!pq.empty()) {
            auto [height, coord] = pq.top();
            pq.pop();
            int x = coord.first, y = coord.second;

            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

                totalWater += max(0, height - heightMap[nx][ny]);

                pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return totalWater;
    }
};
