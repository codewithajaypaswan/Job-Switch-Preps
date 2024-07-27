class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26, vector<long long>(26, 1e9));
        int n = source.size();
        for(int i=0; i<original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long wt = cost[i];
            adj[u][v] = min(adj[u][v], wt);
        }
        for(int via = 0; via < 26; via++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    if(adj[i][via] == 1e9 || adj[via][j] == 1e9) continue;
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(adj[u][v] == 1e9) return -1;
            // cout<<adj[u][v]<<" "<<source[i]<<" "<<target[i]<<endl;
            ans += adj[u][v];
        }
        return ans;
    }
};