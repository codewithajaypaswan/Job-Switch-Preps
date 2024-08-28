class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid2[i][j] == 1) {
                    bool ans = true;
                    dfs(grid1, grid2, i, j, ans);
                    if(ans) cnt++;
                }
            }
        }
        return cnt;
    }
    bool dfs(vector<vector<int>>&grid1, vector<vector<int>>&grid2, int x, int y, bool &ans) {
        if(x < 0 || x >= grid1.size() || y < 0 || y >= grid1[0].size() || grid2[x][y] == 0) return false;
        if(grid1[x][y] == 0) return ans = false;
        grid2[x][y] = 0;
        for(int i=0; i<4; i++) {
            dfs(grid1, grid2, x+dx[i], y+dy[i], ans);
        }
        return ans;
    }
};