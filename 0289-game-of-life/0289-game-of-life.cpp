class Solution {
public:
    const int live = 2, die = 3;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int around = cntLife(board, i, j);
                if(board[i][j] == 0 && around == 3) board[i][j] = live;
                else if(board[i][j] && (around > 3 || around < 2)) board[i][j] = die;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == live) board[i][j] = 1;
                else if(board[i][j] == die) board[i][j] = 0;
            }
        }
    }
    int cntLife(vector<vector<int>>&board, int x, int y) {
        int ans = 0;
        for(int i=0; i<8; i++) {
            int curX = x + dx[i];
            int curY = y + dy[i];
            if(curX >= 0 && curX < board.size() && curY >= 0 && curY < board[0].size() && (board[curX][curY] == 1 || board[curX][curY] == die)) {
                ans++;
            }
        }
        return ans;
    }
};