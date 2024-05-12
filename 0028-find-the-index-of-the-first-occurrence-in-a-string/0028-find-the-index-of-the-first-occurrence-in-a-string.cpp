class Solution {
public:
    vector<int> kmp(string &str) {
        int n = str.size();
        vector<int>lps(n, 0);
        int i = 1, j = 0;
        while(i < n) {
            if(str[i] == str[j]) {
                lps[i++] = ++j;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        vector<int>lps = kmp(needle);
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                i++; j++;
                if(j == m) return i - m;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return -1;
    }
};