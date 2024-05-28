class UnionFind{
    public int[] parent;
    public int[] rank;
    UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        Arrays.fill(parent, -1);
        Arrays.fill(rank, -1);
    }
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    void _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }
        else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
}
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    int u = uf.find(i);
                    int v = uf.find(j);
                    uf._union(u, v);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(uf.parent[i] == -1) ans++;
        }
        return ans;
    }
}