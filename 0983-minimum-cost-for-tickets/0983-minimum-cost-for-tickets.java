class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Set<Integer> st = new HashSet<>();
        for(int x:days) {
            st.add(x);
        }
        int[] dp = new int[366];
        for(int i=1; i<=365; i++) {
            if(!st.contains(i)) dp[i] = dp[i-1];
            else dp[i] = min(costs[0] + dp[i-1], costs[1] + dp[Math.max(0, i-7)], costs[2] + dp[Math.max(0, i-30)]);
        }
        return dp[365];
    }
    
    private int min(int x, int y, int z) {
        return Math.min(Math.min(x, y), z);
    }
}