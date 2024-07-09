class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;
        long total = 0, start = 0;
        for(int i=0; i<n; i++) {
            long end = Math.max(start, customers[i][0]) + customers[i][1];
            total += end - customers[i][0];
            start = end;
        }
        return (double) (double) total / (double) n;
    }
}