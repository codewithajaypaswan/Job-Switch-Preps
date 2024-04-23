class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>&grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(int i=0; i<4; i++) {
            dfs(grid, x+dx[i], y+dy[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};