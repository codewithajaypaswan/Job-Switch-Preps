class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] == B[0] ? A[1] < B[1] : A[0] < B[0];
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);
        int ans = 0, n = meetings.size();
        ans += meetings[0][0] - 1;
        for(int i=1; i<n; i++) {
            if(meetings[i][0] <= meetings[i-1][1]) {
                meetings[i][1] = max(meetings[i][1], meetings[i-1][1]);
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
};