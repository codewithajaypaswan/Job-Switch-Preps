class UnionFind {
public:
    vector<int>parent, rank;
    UnionFind(int size) {
        parent.resize(size, -1);
        rank.resize(size, 1);
    }
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    void _union(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if(parentU == parentV) return;
        if(rank[parentU] > rank[parentV]) {
            rank[parentU] += rank[parentV];
            parent[parentV] = parentU; 
        }
        else {
            rank[parentV] += rank[parentU];
            parent[parentU] = parentV;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    uf._union(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(uf.parent[i] == -1) cnt++;
            
        }
        return cnt;
    }
};