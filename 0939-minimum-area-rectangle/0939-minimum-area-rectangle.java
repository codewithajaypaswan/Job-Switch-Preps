class Solution {
    public int minAreaRect(int[][] points) {
        Map<Integer, Set<Integer>>mp = new HashMap<>();
        for(int[] p: points) {
            if(!mp.containsKey(p[0])) {
                mp.put(p[0], new HashSet<>());
            }
            mp.get(p[0]).add(p[1]);
        }
        int ans = Integer.MAX_VALUE, n = points.length;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 || y1 == y2) continue;
                if(mp.get(x1).contains(y2) && mp.get(x2).contains(y1)) {
                    ans = Math.min(ans, Math.abs(x2 - x1) * Math.abs(y2 - y1));
                }
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}