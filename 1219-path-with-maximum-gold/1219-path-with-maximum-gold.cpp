class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) {
                    dfs(grid, i, j, vis, 0);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&vis, int curGold) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == 1) return;
        int cur = grid[i][j];
        curGold += cur;
        vis[i][j] = 1;
        for(int x=0; x<4; x++) {
            dfs(grid, i+dx[x], j+dy[x], vis, curGold);
        }
        ans = max(ans, curGold);
        vis[i][j] = 0;
        curGold -= cur;
    }
};