class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>dp(m);
        for(int i=0; i<m; i++) dp[i] = mat[0][i];
        for(int i=1; i<n; i++) {
            vector<int>temp(m, 0);
            for(int j=0; j<m; j++) {
                if(j == 0 && j+1 < m) 
                    temp[j] = mat[i][j] + min(dp[j], dp[j+1]);
                else if(j == m-1 && j-1 >= 0) 
                    temp[j] = mat[i][j] + min(dp[j], dp[j-1]);
                else if(j > 0 && j+1 < m) 
                    temp[j] = mat[i][j] + min({dp[j], dp[j-1], dp[j+1]});
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};