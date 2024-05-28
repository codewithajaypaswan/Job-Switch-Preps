class Solution {
    public int minimumScore(String s, String t) {
        int n = s.length(), m = t.length();
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        for(int i=0, j = 0; i<n && j<m; i++) {
            if(s.charAt(i) == t.charAt(j)) {
                prefix[i]++;
                j++;
            }
            if(i > 0) prefix[i] += prefix[i-1];
        }
        for(int i=n-1, j = m-1; i>=0 && j>=0; i--) {
            if(s.charAt(i) == t.charAt(j)) {
                suffix[i]++;
                j--;
            }
            if(i < n-1) suffix[i] += suffix[i+1];
        }
        int ans = Integer.MAX_VALUE;
        for(int i=0; i<n-1; i++) {
            ans = Math.min(ans, m - (prefix[i] + suffix[i+1]));
        }
        ans = Math.min(ans, m - prefix[n-1]);
        ans = Math.min(ans, m - suffix[0]);
        return Math.max(0, ans);
    }
}