class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = 1e9;
            }
        }
        while(!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int curX = x + dx[i];
                int curY = y + dy[i];
                if(curX >= 0 && curX < n && curY >= 0 && curY < m && mat[curX][curY] > mat[x][y] + 1) {
                    mat[curX][curY] = mat[x][y] + 1;
                    q.push({curX, curY});
                }
            }
        }
        return mat;
    }
};