class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int>freq(26, 0);
        for(int high = 0, low = 0, mx_cnt = 0; high < s.size(); high++) {
            freq[s[high] - 'A']++;
            mx_cnt = max(mx_cnt, freq[s[high] - 'A']);
            while(high - low + 1 - mx_cnt > k) {
                freq[s[low] - 'A']--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};