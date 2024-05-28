class Solution {
    int[] dx = new int[] {1, 0, -1, 0};
    int[] dy = new int[] {0, 1, 0, -1};
    public int numEnclaves(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 1) dfs(grid, i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
    
    void dfs(int[][] grid, int x, int y) {
        if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) return;
        grid[x][y] = 0;
        for(int i=0; i<4; i++) {
            dfs(grid, x+dx[i], y+dy[i]);
        }
    }
}