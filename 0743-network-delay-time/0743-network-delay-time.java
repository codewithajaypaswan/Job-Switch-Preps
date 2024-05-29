class Solution {
    static final int mx = 1_000_000_000;
    public int networkDelayTime(int[][] times, int n, int k) {
        int[] dist = new int[n+1];
        Arrays.fill(dist, mx);
        dist[k] = 0;
        for(int i=0; i<n-1; i++) {
            for(int[] t:times) {
                int u = t[0], v = t[1], wt = t[2];
                if(dist[u] != mx && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = Math.max(ans, dist[i]);
        }
        return ans == mx ? -1 : ans;
    }
}