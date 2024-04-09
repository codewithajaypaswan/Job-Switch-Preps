class Solution {
public:
    int dfs(vector<vector<int>>&stones, int cur, vector<int>&visited) {
        if(visited[cur]) return 0;
        visited[cur] = 1;
        int ans = 0;
        for(int i=0; i<stones.size(); i++) {
            if(!visited[i] && (stones[i][0] == stones[cur][0] || stones[i][1] == stones[cur][1])) {
                ans += dfs(stones, i, visited) + 1;
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0;
        vector<int>visited(n, 0);
        for(int i=0; i<n; i++) {
            if(visited[i]) continue;
            ans += dfs(stones, i, visited);
        }
        return ans;
    }
};