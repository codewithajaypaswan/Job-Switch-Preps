class Solution {
public:
    int solve(string &s, int low, int high) {
        int ans = 0;
        while(low >= 0 && high < s.size() && s[low] == s[high]) {
            ans++;
            low--;
            high++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            ans += solve(s, i, i); // for odd length
            ans += solve(s, i, i+1); // for even length
        }
        return ans;
    }
};