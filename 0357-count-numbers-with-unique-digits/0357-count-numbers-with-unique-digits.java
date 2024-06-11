class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10, availableDigits = 9, uniqueDigits = 9;
        while(n > 1) {
            uniqueDigits = availableDigits * uniqueDigits;
            ans += uniqueDigits;
            availableDigits--;
            n--;
        }
        return ans;
    }
}