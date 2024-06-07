class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int len = 0;
        vector<vector<int>>mat(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    if(i != 0 && j != 0) {
                        mat[i][j] = min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]}) + 1;
                    }
                    len = max(len, mat[i][j]);
                }
            }
        }
        return len * len;
    }
};