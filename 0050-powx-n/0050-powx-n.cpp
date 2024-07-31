class Solution {
public:
    double solve(double x, long N) {
        if(N == 0) return 1;
        if(N%2 == 0) return solve(x*x, N/2);
        else return x * solve(x*x, (N-1)/2);
    }
    double myPow(double x, int n) {
        long N = abs(n);
        double ans = solve(x, N);
        return n < 0 ? 1/ans : ans;
    }
};