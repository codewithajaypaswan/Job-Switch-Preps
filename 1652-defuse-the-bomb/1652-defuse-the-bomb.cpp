class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n), sum(2*n);
        if(k == 0) return ans;
        if(k < 0) {
            reverse(code.begin(), code.end());
        }
        sum[0] = code[0];
        for(int i=1; i<2*n; i++) {
            sum[i] += sum[i-1] + code[i%n];
        }
        for(int i=0; i<n; i++) {
            int nextPos = i+abs(k);
            int nextSum = sum[nextPos] - sum[i];
            ans[i] = nextSum;
        }
        if(k < 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};