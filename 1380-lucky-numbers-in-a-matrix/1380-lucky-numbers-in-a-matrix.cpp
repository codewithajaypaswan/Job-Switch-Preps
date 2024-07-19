class Solution {
public:
    int solve(vector<vector<int>>&mat, int row, int col) {
        int mx = INT_MIN;
        for(int i=0; i<mat.size(); i++) {
            mx = max(mx, mat[i][col]);
        }
        int mn = INT_MAX;
        for(int i=0; i<mat[0].size(); i++) {
            mn = min(mn, mat[row][i]);
        }
        return mx == mn;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(solve(matrix, i, j)) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};