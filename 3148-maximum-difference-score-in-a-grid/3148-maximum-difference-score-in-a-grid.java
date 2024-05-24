class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int res = Integer.MIN_VALUE, n = grid.size(), m = grid.get(0).size();
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid.get(0).size(); j++) {
                int mn = Math.min(i > 0 ? grid.get(i-1).get(j) : 1000_000, j > 0 ? grid.get(i).get(j-1) : 1000_000);
                res = Math.max(res, grid.get(i).get(j) - mn);
                grid.get(i).set(j, Math.min(mn, grid.get(i).get(j)));
            }
        }
        return res;
    }
}