class Solution {
    int[][] solve(char[][] grid, char ch) {
        int n = grid.length, m = grid[0].length;
        int[][] sum = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == ch) sum[i][j] = 1;
                if(i > 0) sum[i][j] += sum[i-1][j];
                if(j > 0) sum[i][j] += sum[i][j-1];
                if(i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
            }
        }
        return sum;
    }
    public int numberOfSubmatrices(char[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] xGrid = solve(grid, 'X');
        int[][] yGrid = solve(grid, 'Y');
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(xGrid[i][j] == yGrid[i][j] && xGrid[i][j] > 0) ans++;
            }
        }
        return ans;
    }
}