class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int ans = 0;
        for(int high = 0, low = 0; high < s.size(); high++) {
            mp[s[high]]++;
            while(mp[s[high]] > 1) {
                mp[s[low]]--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};