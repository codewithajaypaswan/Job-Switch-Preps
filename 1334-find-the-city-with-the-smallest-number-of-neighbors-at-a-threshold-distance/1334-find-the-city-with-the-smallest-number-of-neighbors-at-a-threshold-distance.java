class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] adj = new int[n][n];
        for(int i=0; i<n; i++) {
            Arrays.fill(adj[i], Integer.MAX_VALUE);
        }
        for(int []e:edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int via = 0; via < n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(adj[i][via] == Integer.MAX_VALUE || adj[via][j] == Integer.MAX_VALUE) continue;
                    adj[i][j] = Math.min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        int city = -1, minCnt = Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(i != j && adj[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }
        return city;
    }
}
/*

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        List<int[]>[] adj = new ArrayList[n];
        for(int i=0; i<n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int[] e:edges) {
            adj[e[0]].add(new int[] {e[1], e[2]});
            adj[e[1]].add(new int[] {e[0], e[2]});
        }
        int minCnt = Integer.MAX_VALUE, city = -1;
        for(int i=0; i<n; i++) {
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            int[] dist = new int[n];
            int[] vis = new int[n];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[i] = 0;
            pq.add(new int[]{0, i});
            while(!pq.isEmpty()) {
                int[] it = pq.poll();
                int u = it[1];
                vis[u] = 1;
                for(int[] x: adj[u]) {
                    int v = x[0], wt = x[1];
                    if(vis[v] == 0 && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                        pq.add(new int[] {dist[v], v});
                    }
                }
            }
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[j] <= distanceThreshold) cnt++;
            }
            if(cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }
        return city;
    }
}

*/