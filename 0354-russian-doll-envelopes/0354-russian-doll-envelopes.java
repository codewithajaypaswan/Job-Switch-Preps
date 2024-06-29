class Solution {
    public int maxEnvelopes(int[][] env) {
        Arrays.sort(env, (a, b) -> {
            if(a[0] == b[0]) return b[1] - a[1];
            else return a[0] - b[0];
        });
        int n = env.length;
        List<Integer> ans = new ArrayList<>();
        ans.add(env[0][1]);
        for(int i=1; i<n; i++) {
            if(ans.get(ans.size()-1) < env[i][1]) {
                ans.add(env[i][1]);
            }
            else {
                int ind = Collections.binarySearch(ans, env[i][1]);
                if(ind < 0) ind = -(ind + 1);
                ans.set(ind, env[i][1]);
            }
        }
        return (int) ans.size();
    }
}