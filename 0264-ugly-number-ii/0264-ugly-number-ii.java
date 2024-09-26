class Solution {
    public int nthUglyNumber(int n) {
        if(n==1) return 1;
        PriorityQueue<Long> pq = new PriorityQueue();
        pq.add(1l);

        for(long i=1; i<n; i++) {
            long cur = pq.poll();
            while(!pq.isEmpty() && pq.peek() == cur) pq.poll();

            pq.add(cur*2);
            pq.add(cur*3);
            pq.add(cur*5);
        }
        return pq.poll().intValue();
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