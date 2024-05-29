class Solution {
    // const mx = 1_000_000_000;
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int []t:times) {
            adj.get(t[0]).add(new int[] {t[1], t[2]});
        }
        PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int[] dist = new int[n+1];
        int[] vis = new int[n+1];
        Arrays.fill(dist, 1_000_000_000);
        dist[k] = 0;
        pq.offer(new int[] {0, k});
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0], u = cur[1];
            vis[u] = 1;
            for(int[] temp: adj.get(u)) {
                int v = temp[0], wt = temp[1];
                if(vis[v] == 0 && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = Math.max(ans, dist[i]);
        }
        return ans == 1_000_000_000 ? -1 : ans;
    }
}