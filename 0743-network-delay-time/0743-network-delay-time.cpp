class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        for(int i=0; i<n-1; i++) {
            for(auto t:times) {
                int u = t[0], v = t[1], wt = t[2];
                if(dist[u] != 1e9 && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) 
            ans = max(ans, dist[i]);
        return ans == 1e9 ? -1 : ans;
    }
};