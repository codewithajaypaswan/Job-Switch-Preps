class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(31, 0);
        unordered_set<int>st(days.begin(), days.end());
        for(int i=days.front(); i<=days.back(); i++) {
            if(st.find(i) == st.end()) dp[i%30] = dp[(i-1)%30];
            else dp[i%30] = min({costs[0] + dp[(i-1)%30], costs[1] + dp[max(0, i-7) % 30], costs[2] + dp[max(0, i-30) % 30]});
        }
        return dp[days.back()%30];
    }
};