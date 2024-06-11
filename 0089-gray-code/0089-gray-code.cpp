class Solution {
public:
    vector<int>ans;
    vector<int> grayCode(int n) {
        ans.push_back(0);
        for(int i=0; i<n; i++) {
            int mask = (1<<i);
            for(int j=ans.size()-1; j>=0; j--) {
                ans.push_back(ans[j] ^ mask);
            }
        }
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