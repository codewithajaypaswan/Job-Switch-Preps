class Solution {
    int solve(String s, int low, int high) {
        int ans = 0;
        while(low >= 0 && high < s.length() && s.charAt(low) == s.charAt(high)) {
            low--; high++;
            ans++;
        }
        return ans;
    }
    public int countSubstrings(String s) {
        int ans = 0, n = s.length();
        for(int i=0; i<n; i++) {
            ans += solve(s, i, i); // for odd length
            ans += solve(s, i, i+1);
        }
        return ans;
    }
}