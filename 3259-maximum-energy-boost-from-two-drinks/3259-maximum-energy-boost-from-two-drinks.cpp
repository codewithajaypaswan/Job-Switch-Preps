class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>>dp(n, vector<long long>(2, -1));
        long long case1 = solve(energyDrinkA, energyDrinkB, 0, 'A', dp);
        long long case2 = solve(energyDrinkA, energyDrinkB, 0, 'B', dp);
        return max(case1, case2);
    }
    long long solve(vector<int>&A, vector<int>&B, int cur, char ch, vector<vector<long long>>&dp) {
        if(cur >= A.size()) return 0;
        long long ans1 = LONG_MIN, ans2 = LONG_MIN;
        if(dp[cur][ch - 'A'] != -1) return dp[cur][ch - 'A'];
        if(ch == 'A') {
            ans1 = A[cur] + solve(A, B, cur+1, 'A', dp);
            ans2 = solve(A, B, cur+1, 'B', dp);
        }
        else {
            ans1 = B[cur] + solve(A, B, cur+1, 'B', dp);
            ans2 = solve(A, B, cur+1, 'A', dp);
        }
        return dp[cur][ch - 'A'] = max(ans1, ans2);
    }
};