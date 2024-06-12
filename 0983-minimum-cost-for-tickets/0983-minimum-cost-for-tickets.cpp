class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366, 0);
        unordered_set<int>st(days.begin(), days.end());
        for(int i=1; i<=365; i++) {
            if(st.find(i) == st.end()) dp[i] = dp[i-1];
            else dp[i] = min({costs[0] + dp[i-1], costs[1] + dp[max(0, i-7)], costs[2] + dp[max(0, i-30)]});
        }
        return dp[365];
    }
};