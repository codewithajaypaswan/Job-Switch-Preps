class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length, cnt = 0;
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj.get(i).add(j);
                }
            }
        }
        int[]vis = new int[n];
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(List<List<Integer>>adj, int[] vis, int ind) {
        if(vis[ind] == 1) return;
        vis[ind] = 1;
        for(int child:adj.get(ind)) {
            dfs(adj, vis, child);
        }
    }
}