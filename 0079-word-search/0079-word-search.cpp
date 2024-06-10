class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int row, int col, vector<vector<char>>&board, string &word, int cur) {
        if(cur >= word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[cur] || board[row][col] == '.') return false;
        char ch = word[cur];
        board[row][col] = '.';
        for(int i=0; i<4; i++) {
            if(dfs(row + dx[i], col + dy[i], board, word, cur+1)) return true;
        }
        board[row][col] = ch;
        return false;
    }
};