class Solution {
public:
    int find(int u, vector<int>&parent) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u], parent);
    }
    bool _union(int u, int v, vector<int>&parent, vector<int>&rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu == pv) return false;
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += 1;
        }
        else {
            parent[pu] = pv;
            rank[pv] += 1;
        }
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int cnt = 0;
        vector<int>parent(n+1, -1), rank(n+1, 0);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    if(_union(i, j, parent, rank)) cnt++;
                }
            }
        }
        return cnt;
    }
};