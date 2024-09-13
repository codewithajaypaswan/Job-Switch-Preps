class Solution {
    public boolean hasAlternatingBits(int n) {
        long x = n>>1;
        x = x ^ n;
        return (x&(x+1)) == 0;
    }
}