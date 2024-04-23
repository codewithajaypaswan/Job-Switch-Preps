class Solution {
public:
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        if(grid.empty() || grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        grid[0][0] = 1;
        q.push({0, 0});
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                auto[x, y] = q.front(); q.pop();
                if(x == n-1 && y == m-1) return ans;
                for(int i=0; i<8; i++) {
                    int curX = x + dx[i];
                    int curY = y + dy[i];
                    if(curX >= 0 && curX < n && curY >= 0 && curY < m && grid[curX][curY] == 0) {
                        grid[curX][curY] = 1;
                        q.push({curX, curY});
                    }
                }
            }
        }
        return -1;
    }
};