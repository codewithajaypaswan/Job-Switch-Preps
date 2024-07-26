class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int city = -1, minCnt = INT_MAX;
        for(int i=0; i<n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            vector<int>dist(n, 1e9), vis(n, 0);
            pq.push({0, i});
            dist[i] = 0;
            while(!pq.empty()) {
                auto it = pq.top(); pq.pop();
                int u = it.second;
                vis[u] = 1;
                for(auto [v, wt]:adj[u]) {
                    if(vis[v] == 0 && dist[v] > dist[u] + wt) {
                        dist[v] = wt + dist[u];
                        pq.push({dist[v], v});
                    }
                }
            }
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(dist[i] <= distanceThreshold) cnt++;
            }
            if(cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }
        return city;
    }
};
/*

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n, vector<int>(n, INT_MAX));
        for(auto e:edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(adj[i][via] == INT_MAX || adj[via][j] == INT_MAX) continue;
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        int city, minCnt = INT_MAX;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(i != j && adj[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }
        return city;
    }
};

*/