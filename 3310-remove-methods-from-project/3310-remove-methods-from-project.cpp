class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto e:invocations) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int>vis(n, 0);
        solve(k, vis, adj);
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                // if this is not visited and invoke the visited node then add all the nodes
                for(int child:adj[i]) {
                    if(vis[child]) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) ans.push_back(i);
            else if(flag == true) ans.push_back(i);
        }
        return ans;
    }
    void solve(int cur, vector<int>&vis, vector<int>adj[]) {
        if(vis[cur] == 1) return;
        vis[cur] = 1;
        for(int child:adj[cur]) {
            solve(child, vis, adj);
        }
    }
};