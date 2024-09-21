class Solution {
public:
    vector<int>ans;
    vector<int> lexicalOrder(int n) {
        // solve(n, 1);
        int cur = 1;
        for(int i=1; i<=n; i++) {
            ans.push_back(cur);
            if(cur*10 <= n) {
                cur = cur * 10;
            }
            else if(cur + 1 <= n && cur%10 != 9) {
                cur = cur + 1;
            }
            else {
                while((cur/10)%10 == 9) cur = cur / 10;
                cur = cur/10 + 1;
            }
        }
        return ans;
    }
    void solve(int n, int cur) {
        if(cur > n) return;
        ans.push_back(cur);
        solve(n, cur * 10);
        if(cur%10 != 9) solve(n, cur + 1);
    }
};