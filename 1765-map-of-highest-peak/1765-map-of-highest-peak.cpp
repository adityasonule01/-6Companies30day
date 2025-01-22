class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& iswater) {
        int m = iswater.size();
        int n = iswater[0].size();
        
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<p> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (iswater[i][j] == 1) {
                    height[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        

        while (!que.empty()) {
            p curr = que.front();
            que.pop();
            int i = curr.first;
            int j = curr.second;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                    height[i_][j_] = height[i][j] + 1;
                    que.push({i_, j_});
                }
            }
        }
        return height;
    }
};
