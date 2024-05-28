class UnionFind {
public:
    vector<int>rank, parent;
    UnionFind(int size) {
        rank.resize(size, 1);
        parent.resize(size, -1);
    }
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(rank[pu] > rank[pv]) {
            rank[pu]++;
            parent[pv] = pu;
        }
        else {
            rank[pv]++;
            parent[pu] = pv;
        }
        return true;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), cnt = 0;
        UnionFind uf(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    if(uf._union(i, j)) cnt++;
                }
            }
        }
        return cnt;
    }
};