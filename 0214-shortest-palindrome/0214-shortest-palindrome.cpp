class Solution {
public:
    string shortestPalindrome(string s) {
        int len = find_prefix(s), n = s.size();
        string middle = s.substr(0, len);
        string left = s.substr(len);
        string right = left;
        reverse(left.begin(), left.end());
        return left + middle + right;
    }
    int find_prefix(string &str) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        string s = str + "*" + rev;
        int n = s.size();
        vector<int>lps(n);
        int i = 1, j = 0;
        while(i < n) {
            if(s[i] == s[j]) {
                lps[i++] = ++j;
            }
            else if(j == 0) i++;
            else j = lps[j-1];
        }
        return lps[n-1];
    }
};