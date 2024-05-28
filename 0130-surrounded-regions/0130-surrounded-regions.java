class Solution {
    int[] dx = new int[]{1, 0, -1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    int n,m;
    public void solve(char[][] board) {
        n = board.length;
        m = board[0].length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O') {
                    if(i == 0 || i == n-1 || j == 0 || j == m-1)
                        dfs(board, i, j);
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
    
    public void dfs(char[][] board, int x, int y) {
        board[x][y] = '1';
        for(int i=0; i<4; i++) {
            int curX = x + dx[i];
            int curY = y + dy[i];
            if(curX >= 0 && curX < n && curY >= 0 && curY < m && board[curX][curY] == 'O') {
                dfs(board, curX, curY);
            }
        }
    }
}