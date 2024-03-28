class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int>mp;
        for(int high = 0, low = 0, mx = 0; high < n; high++) {
            mp[nums[high]]++;
            mx = max(mx, mp[nums[high]]);
            while(mx > k) {
                mp[nums[low]]--;
                if(nums[low++] == nums[high]) {
                    mx--;
                    break;
                }
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};