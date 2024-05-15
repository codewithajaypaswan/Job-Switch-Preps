class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool check(vector<vector<int>>&grid, int cnt) {
        int n = grid.size();
        if(grid[0][0] < cnt) return false;
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            int sz = q.size();
            while(!q.empty()) {
                auto[x, y] = q.front(); q.pop();
                if(x == n-1 && y == n-1) return true;
                for(int i=0; i<4; i++) {
                    int curX = x + dx[i], curY = y + dy[i];
                    if(curX < 0 || curX >= n || curY < 0 || curY >= n || vis[curX][curY]) continue;
                    if(grid[curX][curY] < cnt) continue;
                    vis[curX][curY] = 1;
                    q.push({curX, curY});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                }
            }
        }
        int dist = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto[x, y] = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int curX = x + dx[i], curY = y + dy[i];
                    if(curX >= 0 && curX < n && curY >= 0 && curY < n && vis[curX][curY] == 0) {
                        vis[curX][curY] = 1;
                        grid[curX][curY] = dist;
                        q.push({curX, curY});
                    }
                }
            }
            dist++;
        }
        int low = 0, high = 1e9, ans;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(grid, mid)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};