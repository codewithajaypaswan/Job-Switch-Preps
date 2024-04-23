class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i, j});
                    while(!q.empty()) {
                        auto[x, y] = q.front(); q.pop();
                        for(int i=0; i<4; i++) {
                            int curX = x + dx[i];
                            int curY = y + dy[i];
                            if(curX >= 0 && curX < n && curY >= 0 && curY < m && grid[curX][curY] == '1') {
                                grid[curX][curY] = '0';
                                q.push({curX, curY});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};