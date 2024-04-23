class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>&grid, int x, int y) {
       if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return;
        grid[x][y] = 0;
        for(int i=0; i<4; i++) {
            dfs(grid, x+dx[i], y+dy[i]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    dfs(grid, i, j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};