class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n, vector<int>(n, INT_MAX));
        for(auto e:edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int via=0; via < n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(adj[i][via] == INT_MAX || adj[via][j] == INT_MAX) continue;
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        int minCnt = INT_MAX, city = -1;
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
};