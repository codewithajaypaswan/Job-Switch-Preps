class Solution {
public:
    long long dp[102][102][102][3];
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        memset(dp, -1, sizeof(dp));
        
        vector<pair<int, int>>adj[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                adj[i].push_back({board[i][j], j});
            }
            sort(adj[i].rbegin(), adj[i].rend());
            while(adj[i].size() > 3) {
                adj[i].pop_back();
            }
        }
        return solve(adj, 101, 101, n, m, 0, 0);
    }
    long long solve(vector<pair<int, int>>adj[], int a, int b, int n, int m, int cnt, int cur) {
        if(cnt == 3) return 0;
        if(cur >= n) return -1e12;
        if(dp[cur][a][b][cnt] != -1) return dp[cur][a][b][cnt];
        long long case1 = -1e12, case2 = -1e12; // either put a rook or not put a rook
        for(auto it:adj[cur]) {
            int k = it.second, val = it.first;
            if(a != k && b != k) {
                // now we can place the3 rook
                if(a == 101)
                    case1 = max(case1, solve(adj, k, b, n, m, cnt+1, cur+1) + 1LL * val);
                else if(b == 101) 
                    case1 = max(case1, solve(adj, a, k, n, m, cnt+1, cur+1) + 1LL * val);
                else
                    case1 = max(case1, solve(adj, a, b, n, m, cnt+1, cur+1) + 1LL * val);
            }
        }
        // without putting the rook
        case2 = max(case2, solve(adj, a, b, n, m, cnt, cur+1));
        return dp[cur][a][b][cnt] = max(case1, case2);
    }
};