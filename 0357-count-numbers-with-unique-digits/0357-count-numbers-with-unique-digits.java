class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        int[] vis = new int[10];
        return solve(n, vis, 0);
    }
    private int solve(int n, int[] vis, int cur) {
        if(cur == n) return 1;
        int res = 1;
        for(int i=cur == 0 ? 1 : 0; i <= 9; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                res += solve(n, vis, cur+1);
                vis[i] = 0;
            }
        }
        return res;
    }
}
/*
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10, availableDigits = 9, uniqueDigits = 9;
        while(n > 1) {
            uniqueDigits = availableDigits * uniqueDigits;
            ans += uniqueDigits;
            availableDigits--;
            n--;
        }
        return ans;
    }
}
*/