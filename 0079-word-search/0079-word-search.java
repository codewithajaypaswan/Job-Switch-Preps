class Solution {
    int []dx = new int[]{1, 0, -1, 0};
    int []dy = new int[]{0, 1, 0, -1};
    public boolean exist(char[][] board, String word) {
        int n = board.length, m = board[0].length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word.charAt(0)) {
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    private boolean dfs(char[][] board, String word, int i, int j, int cur) {
        if(cur >= word.length()) return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(cur) || board[i][j] == '.') return false;
        char ch = board[i][j];
        board[i][j] = '.';
        for(int k=0; k<4; k++) {
            if(dfs(board, word, i+dx[k], j+dy[k], cur+1)) return true;
        }
        board[i][j] = ch;
        return false;
    }
}