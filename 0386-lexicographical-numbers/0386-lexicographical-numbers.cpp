class Solution {
public:
    vector<int>ans;
    vector<int> lexicalOrder(int n) {
        solve(n, 1);
        return ans;
    }
    void solve(int n, int cur) {
        if(cur > n) return;
        ans.push_back(cur);
        solve(n, cur * 10);
        if(cur%10 != 9) solve(n, cur + 1);
    }
};