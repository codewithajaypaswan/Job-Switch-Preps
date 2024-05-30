class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = max(grid[0][0], grid[n-1][n-1]);
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            int sz = pq.size();
            while(sz--) {
                auto cur = pq.top(); pq.pop();
                ans = max(cur[0], ans);
                if(cur[1] == n-1 && cur[2] == n-1) return ans;
                for(int i=0; i<4; i++) {
                    int x = dx[i]+cur[1];
                    int y = dy[i]+cur[2];
                    if(x<0 || x>=n || y<0 || y>=n || vis[x][y]) continue;
                    vis[x][y] = true;
                    pq.push({grid[x][y], x, y});
                    
                }
            }
        }
        return ans;
    }
};