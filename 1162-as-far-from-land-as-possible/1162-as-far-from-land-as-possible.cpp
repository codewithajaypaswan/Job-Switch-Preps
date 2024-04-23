class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) q.push({i, j});
            }
        }
        int ans = 0;
        while(!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int curX = dx[i] + x;
                int curY = dy[i] + y;
                if(curX >= 0 && curX < n && curY >=0 && curY < m && grid[curX][curY] == 0) {
                    grid[curX][curY] = grid[x][y] + 1;
                    q.push({curX, curY});
                    ans = max(ans, grid[curX][curY]);
                }
            }
        }
        return ans - 1;
    }
};