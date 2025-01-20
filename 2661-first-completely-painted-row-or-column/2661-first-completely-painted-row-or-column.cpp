
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        using pii = pair<int, int>;
        vector<pii> lookup(m * n + 1); // Lookup table to store matrix value coordinates

        // Build the lookup table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lookup[mat[i][j]] = make_pair(i, j);
            }
        }

        vector<int> row_count(m, 0), col_count(n, 0); // Row and column paint counters

        // Process the array to determine the first complete index
        for (int i = 0; i < arr.size(); i++) {
            pii coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;

            // Update the row and column counters
            row_count[x]++;
            col_count[y]++;

            // Check if a row or column is fully painted
            if (row_count[x] == n || col_count[y] == m) {
                return i; // Return the first index where this happens
            }
        }

        return -1; // No complete row or column found
    }
};
