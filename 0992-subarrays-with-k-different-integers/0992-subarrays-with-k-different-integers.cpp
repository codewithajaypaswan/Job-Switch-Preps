class Solution {
public:
    int atMost(vector<int>nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int high = 0, low = 0, cnt = 0; high < nums.size(); high++) {
            cnt += mp[nums[high]] == 0 ? 1 : 0;
            mp[nums[high]]++;
            while(cnt > k) {
                mp[nums[low]]--;
                cnt -= mp[nums[low++]] == 0 ? 1 : 0;
            }
            ans += high - low + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};