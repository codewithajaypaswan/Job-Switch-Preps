class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int>mp;
        for(int high = 0, low = 0; high < n; high++) {
            mp[nums[high]]++;
            while(mp[nums[high]] > k) {
                mp[nums[low++]]--;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};