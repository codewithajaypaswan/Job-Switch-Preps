class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid, int x, int y, int curGold) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return;
        int cur = grid[x][y];
        curGold += cur;
        grid[x][y] = 0;
        for(int i=0; i<4; i++) {
            dfs(grid, x+dx[i], y+dy[i], curGold);
        }
        ans = max(ans, curGold);
        grid[x][y] = cur;
        return;
    }
};