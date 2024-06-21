class Solution {
    public int maxSatisfied(int[] c, int[] g, int minutes) {
        int n = c.length, sum = 0;
        for(int i=0; i<n; i++) {
            if(g[i] == 0) sum += c[i];
        }
        int slidingSum = 0;
        for(int high = 0, low = 0, temp = 0; high < n; high++) {
            temp += g[high] == 1 ? c[high] : 0;
            if(high - low + 1 == minutes) {
                slidingSum = Math.max(slidingSum, temp);
                temp -= g[low] == 1 ? c[low] : 0;
                low++;
            }
        }
        return sum + slidingSum;
    }
}