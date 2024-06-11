class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>vis(10, false);
        return solve(n, vis, 0);
    }
    int solve(int n, vector<int>&vis, int cur) {
        if(cur == n) return 1;
        int res = 1;
        for(int i = cur == 0 ? 1 : 0; i <= 9; i++) {
            if(vis[i] == false) {
                vis[i] = true;
                res += solve(n, vis, cur + 1);
                vis[i] = false;
            }
        }
        return res;
    }
};