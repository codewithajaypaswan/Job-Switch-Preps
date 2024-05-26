class Solution {
public:
    int checkRecord(int n) {
        long long ans = 0, mod = 1e9+7;
        long long A[n], L[n], P[n];
        A[0] = L[0] = P[0] = 1;
        if(n == 2) return 8;
        if(n == 1) return 3;
        A[1] = 2;
        L[1] = 3;
        A[2] = 4;
        for(int i=1; i<n; i++) {
            P[i] = ((P[i-1]%mod + A[i-1]%mod)%mod + L[i-1]%mod)%mod;
            if(i >= 2) L[i] = ((P[i-1] + A[i-1])%mod + A[i-2] + P[i-2])%mod;
            if(i >= 3) A[i] = (A[i-1] + A[i-2] + A[i-3])%mod;
        }
        ans = (A[n-1]%mod + P[n-1]%mod + L[n-1]%mod)%mod;
        return ans;
    }
};