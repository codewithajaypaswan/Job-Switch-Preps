class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n, k, temp);
        return ans;
    }
    void solve(int n, int k, vector<int>&temp, int cur = 1) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for(int i=cur; i<=n; i++) {
            temp.push_back(i);
            solve(n, k, temp, i + 1);
            temp.pop_back();
        }
    }
};