class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++) {
            int flag = 0;
            for(int j=0; j<m; j++) {
                int top = i == 0 ? 0 : mat[i-1][j];
                int left = j == 0 ? 0 : mat[i][j-1];
                if(i == 0 && j == 0 && mat[i][j] == 0) mat[i][j] = 1;
                else mat[i][j] = mat[i][j] == 1 ? 0 : top + left;
                
                if(mat[i][j] > 0) flag = 1;
            }
            if(flag == 0) return 0;
        }
        return mat[n-1][m-1];
    }
};