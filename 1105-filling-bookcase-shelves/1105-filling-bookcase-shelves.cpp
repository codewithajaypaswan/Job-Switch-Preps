class Solution {
public:
    int solve(vector<vector<int>>&books, int sw, int width, int height, int cur, vector<vector<int>>&dp) {
        if(cur >= books.size()) return height;
        if(dp[cur][width] != -1) return dp[cur][width];
        int option1 = height + solve(books, sw, books[cur][0], books[cur][1], cur + 1, dp);
        int option2 = 1e9;
        if(width + books[cur][0] <= sw) {
            option2 = min(option2, solve(books, sw, books[cur][0] + width, max(height, books[cur][1]), cur +1, dp));
        }
        return dp[cur][width] = min(option1, option2);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>>dp(n, vector<int>(shelfWidth+1, -1));
        return solve(books, shelfWidth, 0, 0, 0, dp);
    }
};