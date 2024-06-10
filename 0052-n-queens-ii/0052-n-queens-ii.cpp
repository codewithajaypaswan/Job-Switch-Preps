class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        vector<string>temp(n);
        string str(n, '.');
        for(int i=0; i<n; i++) {
            temp[i] = str;
        }
        solve(temp, 0, n);
        return ans;
    }
    
    void solve(vector<string>&temp, int col, int n) {
        if(col >= n) {
            ans++;
            return;
        }
        for(int row=0; row < n; row++) {
            if(isSafe(row, col, temp)) {
                temp[row][col] = 'Q';
                solve(temp, col+1, n);
                temp[row][col] = '.';
            }
        }
    }
    
    bool isSafe(int row, int col, vector<string>&temp) {
        int i = row, j = col, n = temp.size();
        while(j >= 0) {
            if(temp[row][j--] == 'Q') return false; 
        }
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