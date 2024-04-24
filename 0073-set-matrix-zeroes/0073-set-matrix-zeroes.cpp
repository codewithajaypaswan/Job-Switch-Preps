class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int fr = 1, fc = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                    if(i == 0) fr = 0;
                    if(j == 0) fc = 0;
                }
            }
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        if(fr == 0) {
            for(int j=0; j<m; j++) mat[0][j] = 0;
        }
        if(fc == 0) {
            for(int i=0; i<n; i++) mat[i][0] = 0;
        }
    }
};