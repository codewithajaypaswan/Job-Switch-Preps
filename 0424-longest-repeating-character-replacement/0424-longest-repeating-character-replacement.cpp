class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        vector<int>freq(26, 0);
        for(int high = 0, low = 0, mx = 0; high < n; high++) {
            freq[s[high] - 'A']++;
            mx = max(mx, freq[s[high] - 'A']);
            while(high - low + 1 - mx > k) {
                freq[s[low] - 'A']--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};