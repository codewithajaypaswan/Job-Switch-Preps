class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board, int x, int y, string &word, int ind) {
        if(ind >= word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[ind] || board[x][y] == '.') return false;
        char ch = board[x][y];
        board[x][y] = '.';
        for(int i=0; i<4; i++) {
            if(dfs(board, x + dx[i], y + dy[i], word, ind+1)) return true;
        }
        board[x][y] = ch;
        return false;
    }
};