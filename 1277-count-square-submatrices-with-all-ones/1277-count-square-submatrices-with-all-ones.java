class Solution {
    public int countSquares(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    if(i != 0 && j != 0)
                        mat[i][j] = Math.min(Math.min(mat[i-1][j], mat[i][j-1]), mat[i-1][j-1]) + 1;
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
}