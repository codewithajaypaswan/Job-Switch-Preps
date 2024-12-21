class Solution {
public:
    
    // dp array to which is storing the sum of descents including node value
    vector<long> dp;
    int cnt;  
    long dfs(vector<int> adj[],int s,vector<int>&vis,vector<int>& values,int k){
        vis[s]=1;
        for(auto nbr:adj[s]){
            if(!vis[nbr]){
                dp[s]+=dfs(adj,nbr,vis,values,k);
            }
        }
        // going from bottom then coming up
        // if sum till current node is divible by k count in ans and return 0;
        if(dp[s]%k==0){
            cnt++;
            return 0;
        }
        
        return dp[s];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        cnt=0;
        dp.resize(n,0);
        for(int i=0;i<n;i++){
            dp[i]=values[i];
        }
        vector<int> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        dfs(adj,0,vis,values,k);
        
        return cnt;
        
        
    }
};