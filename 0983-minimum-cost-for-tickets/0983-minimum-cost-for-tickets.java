class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Set<Integer> st = new HashSet<>();
        for(int x:days) {
            st.add(x);
        }
        int[] dp = new int[31];
        int n = days.length;
        for(int i=days[0]; i<=days[n-1]; i++) {
            if(!st.contains(i)) dp[i%30] = dp[(i-1)%30];
            else dp[i%30] = min(costs[0] + dp[(i-1)%30], costs[1] + dp[(Math.max(0, i-7))%30], costs[2] + dp[(Math.max(0, i-30))%30]);
        }
        return dp[days[n-1]%30];
    }
    
    private int min(int x, int y, int z) {
        return Math.min(Math.min(x, y), z);
    }
}