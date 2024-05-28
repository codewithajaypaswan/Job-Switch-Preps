class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        for(int high = 0, low = 0; high < n; high++) {
            maxCost -= abs(s[high] - t[high]);
            while(maxCost < 0) {
                maxCost += abs(s[low] - t[low]);
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};