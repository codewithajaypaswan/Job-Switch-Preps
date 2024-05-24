class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int res = INT_MIN, n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int mx = min(i > 0 ? grid[i-1][j] : 1e6, j > 0 ? grid[i][j-1] : 1e6);
                res = max(res, grid[i][j] - mx);
                grid[i][j] = min(grid[i][j], mx);
            }
        }
        return res;
    }
};