class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long total = 0, start = 0;
        for(int i=0; i<customers.size(); i++) {
            long end = max(start, (long) customers[i][0]) + customers[i][1];
            total += end - customers[i][0];
            start = end;
        }
        return (double) total / n;
    }
};