class Solution {
    int ans = 0;
    public int totalNQueens(int n) {
        List<String> temp = new ArrayList<>(n);
        String str = ".".repeat(n);
        for(int i=0; i<n; i++) {
            temp.add(str);
        }
        solve(temp, 0, n);
        return ans;
    }
    
    private void solve(List<String>temp, int col, int n) {
        if(col >= n) {
            ans++;
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(temp, row, col)) {
                char[] chArray = temp.get(row).toCharArray();
                chArray[col] = 'Q';
                temp.set(row, new String(chArray));
                solve(temp, col+1, n);
                chArray[col] = '.';
                temp.set(row, new String(chArray));
            }
        }
    }
    
    private boolean isSafe(List<String>temp, int row, int col) {
        int i = row, j = col, n = temp.size();
        while(j >= 0) {
            if(temp.get(i).charAt(j--) == 'Q') return false;
        }
        j = col;
        while(i >= 0 && j >= 0) {
            if(temp.get(i--).charAt(j--) == 'Q') return false;
        }
        i = row;
        j = col;
        while(i < n && j >= 0) {
            if(temp.get(i++).charAt(j--) == 'Q') return false;
        }
        return true;
    }
}