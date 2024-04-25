class Solution {
public:
    vector<int>kmp(string s) {
        int n = s.size(), i = 1, j = 0;
        vector<int>lps(n);
        lps[0] = 0;
        while(i < n) {
            if(s[i] == s[j]) {
                lps[i++] = ++j;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        vector<int>lps = kmp(needle);
        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                i++; j++;
                if(j == m) return i - m;
            }
            else if(j == 0) {
                i++;
            }
            else {
                j = lps[j-1];
            }
        }
        return -1;
    }
};