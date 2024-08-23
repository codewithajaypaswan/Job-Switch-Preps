class Solution {
    public boolean hasAlternatingBits(int n) {
        int k = (n>>1);
        n = n^k;
        return (n&(n+1)) == 0;
    }
}