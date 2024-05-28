class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(board[i][j] == 'O') dfs(board, i, j);
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
                
            }
        }
    }
    void dfs(vector<vector<char>>&mat, int i, int j) {
        if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != 'O') return;
        mat[i][j] = '1';
        for(int k=0; k<4; k++) {
            dfs(mat, i + dx[k], j + dy[k]);
        }
    }
};