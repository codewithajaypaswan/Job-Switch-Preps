class Solution {
public:
    int helper(int n, int k) {
        // if(n == 1) return 0;
        // return (helper(n-1, k) + k)%n;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = (ans + k)%i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
       return helper(n, k) + 1;
    }
};