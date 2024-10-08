class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        int cnt = 0, ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }
        
        if(cnt == 0) return 0;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto[x, y] = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int curX = x + dx[i];
                    int curY = y + dy[i];
                    if(curX >= 0 && curX < n && curY >= 0 && curY < m && grid[curX][curY] == 1) {
                        grid[curX][curY] = 2;
                        q.push({curX, curY});
                        cnt--;
                    }
                }
            }
            ans++;
        }
        return cnt == 0 ? ans - 1 : -1;
    }
};