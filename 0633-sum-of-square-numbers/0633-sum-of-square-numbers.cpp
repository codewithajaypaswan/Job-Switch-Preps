class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0; a*a <= c; a++) {
            long b = c - a*a;
            if(solve(0, b, b)) return true;
        }
        return false;
    }
    bool solve(long low, long high, long val) {
        if(low > high) return false;
        while(low <= high) {
            long mid = low + (high - low)/2;
            if(mid*mid == val) return true;
            else if(mid*mid > val) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return false;
    }
};