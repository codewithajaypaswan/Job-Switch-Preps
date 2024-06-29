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
            solve(i, adj, ans, i);
        }
        return ans;
    }
    public void solve(int cur, List<List<Integer>>adj, List<List<Integer>>ans, int x) {
        for(int i=0; i<adj.get(cur).size(); i++) {
            int child = adj.get(cur).get(i);
            if(ans.get(child).isEmpty() || ans.get(child).get(ans.get(child).size() - 1) != x) {
                ans.get(child).add(x);
                solve(child, adj, ans, x);
            }
        }
    }
}