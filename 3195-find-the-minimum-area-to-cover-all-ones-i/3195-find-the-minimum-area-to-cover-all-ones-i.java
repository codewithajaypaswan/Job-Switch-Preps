class Solution {
    public int minimumArea(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        List<Integer> horizontal = new ArrayList<>();
        List<Integer> vertical = new ArrayList<>();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    horizontal.add(j);
                    vertical.add(i);
                }
            }
        }
        int h1 = minimum(horizontal);
        int h2 = maximum(horizontal);
        int v1 = minimum(vertical);
        int v2 = maximum(vertical);

        return (h2 - h1 + 1) * (v2 - v1 + 1);
    }
    int maximum(List<Integer>list) {
        int n = list.size(), ans = Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            ans = Math.max(ans, list.get(i));
        }
        return ans;
    }
    int minimum(List<Integer>list) {
        int n = list.size(), ans = Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
            ans = Math.min(ans, list.get(i));
        }
        return ans;
    }
}