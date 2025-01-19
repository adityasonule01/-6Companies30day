class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightmap) {
        if (heightmap.empty() || heightmap[0].empty()) return 0;

        int n = heightmap.size();
        int m = heightmap[0].size();

        priority_queue<pp, vector<pp>, greater<pp>> boundarycells;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Add all boundary cells to the priority queue
        for (int i = 0; i < n; ++i) {
            for (int j : {0, m - 1}) {
                boundarycells.push({heightmap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i : {0, n - 1}) {
                if (!visited[i][j]) {
                    boundarycells.push({heightmap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int water = 0;

        while (!boundarycells.empty()) {
            pp current = boundarycells.top();
            boundarycells.pop();

            int height = current.first;
            int x = current.second.first;
            int y = current.second.second;

            for (vector<int>& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    water += max(0, height - heightmap[nx][ny]);
                    boundarycells.push({max(height, heightmap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return water;
    }
};
