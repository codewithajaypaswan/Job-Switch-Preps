class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        int[] lps = new int[n];
        int i = 1, j = 0;
        while(i < n) {
            if(s.charAt(i) == s.charAt(j)) {
                lps[i++] = ++j;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        int len = lps[n-1];
        int left = n - len;
        return len > 0 && len%left == 0 ;
    }
}