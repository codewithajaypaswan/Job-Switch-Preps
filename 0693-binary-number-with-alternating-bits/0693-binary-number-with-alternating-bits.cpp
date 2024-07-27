class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = (n>>1);
        n = n^k;
        return (n&(1LL * n + 1)) == 0;
    }
};