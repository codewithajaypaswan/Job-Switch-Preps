class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(grid[i][j]) {
                        q.push({i, j});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        while(!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int curX = x + dx[i];
                int curY = y + dy[i];
                if(curX >= 0 && curX < n && curY >= 0 && curY < m && grid[curX][curY] == 1) {
                    grid[curX][curY] = 0;
                    q.push({curX, curY});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};