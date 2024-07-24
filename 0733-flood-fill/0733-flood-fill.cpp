class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur = image[sr][sc];
        if(cur == color) return image;
        dfs(image, sr, sc, color, cur);
        return image;
    }
    void dfs(vector<vector<int>>&image, int r, int c, int color, int cur) {
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != cur) return;
        image[r][c] = color;
        for(int i=0; i<4; i++) {
            dfs(image, r + dx[i], c + dy[i], color, cur);
        }
    }
};