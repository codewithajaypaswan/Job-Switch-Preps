class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for(char c:s) {
            if(c >= '2' && c <= '9') len *= (c - '0');
            else len++;
        }
        for(int i=s.size()-1; i>=0; i--) {
            k = k%len;
            if(k == 0 && !isdigit(s[i])) {
                string ans = "";
                ans += s[i];
                return ans;
            }
            else if(isdigit(s[i])) {
                len /= (s[i] - '0');
            }
            else {
                len--;
            }
        }
        return "";
    }
};