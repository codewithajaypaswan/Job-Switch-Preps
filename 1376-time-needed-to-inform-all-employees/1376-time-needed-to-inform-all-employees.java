class Solution {
    int ans = 0;
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<n; i++) {
            if(i == headID) continue;
            adj.get(manager[i]).add(i);
        }
        dfs(adj, headID, informTime, 0);
        return ans;
    }
    void dfs(List<List<Integer>> adj, int cur, int[] informTime, int sum) {
        sum += informTime[cur];
        ans = Math.max(ans, sum);
        for(int child:adj.get(cur)) {
            dfs(adj, child, informTime, sum);
        }
    }
}