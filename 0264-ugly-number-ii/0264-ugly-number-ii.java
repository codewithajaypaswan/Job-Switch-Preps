class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        HashSet<Long> seen = new HashSet<>();
        
        pq.add(1L);
        seen.add(1L);
        
        long cur = 1;
        for (int i = 1; i < n; i++) {
            cur = pq.poll();
            if (seen.add(cur * 2)) pq.add(cur * 2);
            if (seen.add(cur * 3)) pq.add(cur * 3);
            if (seen.add(cur * 5)) pq.add(cur * 5);
        }
        
        return (int) pq.peek().intValue();
    }
}

/*
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i=1; i<n; i++) {
            int mn = Math.min(dp[p2] * 2, Math.min(dp[p3] * 3, dp[p5] * 5));
            if(mn == dp[p2] * 2) {
                p2++;
            }
            if(mn == dp[p3] * 3) {
                p3++;
            }
            if(mn == dp[p5] * 5) {
                p5++;
            }
            dp[i] = mn;
        }
        return dp[n-1];
    }
}
*/