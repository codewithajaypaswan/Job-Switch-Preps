class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int>vis(10, 0);
        return solve(n, vis, 0);
    }
    int solve(int n, vector<int>&vis, int cur) {
        if(cur == n) {
            return 1;
        }
        int res = 1;
        for(int i=cur == 0 ? 1 : 0; i <= 9; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                res += solve(n, vis, cur + 1);
                vis[i] = 0;
            }
        }
        return res;
    }
};