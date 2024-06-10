class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            temp[i] = s;
        }
        solve(0, temp, n);
        return ans;
    }
    void solve(int col, vector<string>&temp, int n) {
        if(col >= n) {
            ans.push_back(temp);
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(temp, row, col)) {
                temp[row][col] = 'Q';
                solve(col+1, temp, n);
                temp[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string>&temp, int row, int col) {
        int i = row, j = col, n = temp.size();
        // check the row
        while(j >= 0) {
            if(temp[row][j--] == 'Q') return false;
        }
        // check the upper diagonal
        j = col;
        while(i >= 0 && j >= 0) {
            if(temp[i--][j--] == 'Q') return false;
        }
        i = row, j = col;
        while(i < n && j >= 0) {
            if(temp[i++][j--] == 'Q') return false;
        }
        return true;
    }
};