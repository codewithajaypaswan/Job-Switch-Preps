class Solution {
public:
    int solve(vector<vector<int>>&mat, int row, int col, vector<vector<int>>&dp) {
        if(row == mat.size()-1 && col >= 0 && col < mat.size()) return mat[row][col];
        if(col < 0 || col >= mat[0].size()) return INT_MAX;
        if(dp[row][col] != INT_MAX) return dp[row][col];
        return dp[row][col] = mat[row][col] + min({solve(mat, row+1, col, dp), solve(mat, row+1, col-1, dp), solve(mat, row+1, col+1, dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, INT_MAX));
        int ans = INT_MAX;
        for(int c=0; c<m; c++) {
            ans = min(ans, solve(matrix, 0, c, dp));
        }
        return ans;
    }
};