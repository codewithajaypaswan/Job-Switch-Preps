class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> ans = new ArrayList<>();
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            ans.add(i, new ArrayList<>());
            adj.add(i, new ArrayList<>());
        }
        for(int[] e: edges) {
            adj.get(e[0]).add(e[1]);
        }
        for(int i=0; i<n; i++) {
            int[] vis = new int[n];
            solve(i, vis, adj, ans, i);
        }
        return ans;
    }
    public void solve(int cur, int[] vis, List<List<Integer>>adj, List<List<Integer>>ans, int x) {
        vis[cur] = 1;
        for(int i=0; i<adj.get(cur).size(); i++) {
            int child = adj.get(cur).get(i);
            if(vis[child] == 0) {
                ans.get(child).add(x);
                solve(child, vis, adj, ans, x);
            }
        }
    }
}