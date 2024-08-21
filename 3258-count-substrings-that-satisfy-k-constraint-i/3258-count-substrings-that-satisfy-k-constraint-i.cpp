class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0, n = s.size();
        for(int len = 1; len <= n; len++) {
            for(int low = 0, high = 0, cnt1 = 0, cnt0 = 0; high < n; high++) {
                
                if(s[high] == '0') cnt0++;
                else cnt1++;
                
                if(high - low + 1 == len) {
                    if(cnt1 <= k || cnt0 <= k) ans++;
                    
                    if(s[low] == '0') cnt0--;
                    else cnt1--;
                    low++;
                }
            }
        }
        return ans;
    }
};