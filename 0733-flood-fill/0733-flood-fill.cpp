class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<int>>&g, int x, int y, int newColor, int cur) {
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] != cur) return;        
        g[x][y] = newColor;
        for(int i=0; i<4; i++) {
            solve(g, x + dx[i], y + dy[i], newColor, cur);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int cur = image[sr][sc];
        if(cur == newColor) return image;
        solve(image, sr, sc, newColor, cur);
        return image;
    }
};