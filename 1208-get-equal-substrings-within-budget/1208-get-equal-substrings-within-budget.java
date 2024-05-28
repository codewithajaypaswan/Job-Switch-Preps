class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length(), ans = 0;
        for(int high = 0, low = 0; high < n; high++) {
            maxCost -= Math.abs(s.charAt(high) - t.charAt(high));
            while(maxCost < 0) {
                maxCost += Math.abs(s.charAt(low) - t.charAt(low));
                low++;
            }
            ans = Math.max(ans, high - low + 1);
        }
        return ans;
    }
}