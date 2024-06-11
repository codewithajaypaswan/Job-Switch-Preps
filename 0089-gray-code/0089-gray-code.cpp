class Solution {
public:
    vector<int>ans;
    vector<int> grayCode(int n) {
        solve(n);
        return ans;
    }
    void solve(int n) {
        if(n == 0) {
            ans.push_back(0);
            return;
        }
        solve(n-1);
        int mask = (1<<(n-1));
        for(int i=ans.size()-1; i>=0; i--) {
            ans.push_back(mask ^ ans[i]);
        }
    }
};