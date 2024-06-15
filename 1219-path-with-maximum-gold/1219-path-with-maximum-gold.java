class Solution {
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    int ans = 0;
    public int getMaximumGold(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] > 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return ans;
    }
    
    public void dfs(int[][] grid, int x, int y, int curGold) {
        if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) return;
        int cur = grid[x][y];
        grid[x][y] = 0;
        curGold += cur;
        for(int i=0; i<4; i++) {
            dfs(grid, x+dx[i], y+dy[i], curGold);
        }
        ans = Math.max(ans, curGold);
        grid[x][y] = cur;
        return;
    }
}