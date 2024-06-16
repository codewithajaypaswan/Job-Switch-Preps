class Solution {
public:
    double solve(double x, long N) {
        double ans = 1;
        while(N > 0) {
            if(N&1) {
                ans = ans * x;
            }
            N = N/2;
            x = x * x;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long N = abs(n);
        double ans = solve(x, N);
        return n < 0 ? 1/ans : ans;
    }
};
