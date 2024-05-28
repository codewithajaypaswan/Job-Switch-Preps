class Solution {
    int find(int[] parent, int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent, parent[u]);
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n+1];
        Arrays.fill(parent, -1);
        for(int i=0; i<n; i++) {
            int u = find(parent, edges[i][0]);
            int v = find(parent, edges[i][1]);
            if(u == v) return edges[i];
            parent[u] = v;
        }
        return new int[0];
    }
}