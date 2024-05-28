class UnionFind {
    public int[] rank;
    public int[] parent;
    UnionFind(int size) {
        rank = new int[size];
        parent = new int[size];
        Arrays.fill(rank, 1);
        Arrays.fill(parent, -1);
    }
    
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    
    boolean _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        }
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
}
class Solution {
    public int removeStones(int[][] stones) {
        int cnt = 0, n = stones.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    if(uf._union(i, j)) cnt++;
                }
            }
        }
        return cnt;
    }
}