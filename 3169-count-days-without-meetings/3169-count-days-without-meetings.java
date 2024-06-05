class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        int ans = 0, n = meetings.length;
        ans += meetings[0][0] - 1;
        for(int i=1; i<n; i++) {
            if(meetings[i][0] <= meetings[i-1][1]) {
                // merge
                meetings[i][1] = Math.max(meetings[i][1], meetings[i-1][1]);
            }
            else {
                int cnt = meetings[i][0] - meetings[i-1][1] - 1;
                ans += cnt;
            }
        }
        if(meetings[n-1][1] < days) {
            int cnt = days - meetings[n-1][1];
            ans += cnt;
        }
        return ans;
    }
}