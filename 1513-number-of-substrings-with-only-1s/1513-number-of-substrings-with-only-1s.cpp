class Solution {
public:
    int numSub(string s) {
        long long ans = 0, mod = 1e9+7, cnt = 0;
        for(char c:s) {
            cnt = c == '1' ? cnt + 1 : 0;
            ans += cnt;
        }
        return ans%mod;;
    }
};