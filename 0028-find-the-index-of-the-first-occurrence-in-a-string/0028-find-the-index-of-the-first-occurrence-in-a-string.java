class Solution {
    int[] kmp(String str) {
        int n = str.length();
        int[] lps = new int[n];
        int i = 1, j = 0;
        while(i < n) {
            if(str.charAt(i) == str.charAt(j)) {
                lps[i++] = ++j;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return lps;
    }
    public int strStr(String haystack, String needle) {
        int[]lps = kmp(needle);
        int n = haystack.length(), m = needle.length();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(haystack.charAt(i) == needle.charAt(j)) {
                i++; j++;
                if(j == m) return i - m;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return -1;
    }
}