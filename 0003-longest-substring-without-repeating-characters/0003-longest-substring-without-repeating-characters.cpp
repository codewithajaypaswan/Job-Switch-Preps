class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int ans = 0;
        for(int high = 0, low = 0; high < s.size(); high++) {
            while(mp[s[high]] > 0) {
                mp[s[low++]]--;
            }
            mp[s[high]]++;
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};