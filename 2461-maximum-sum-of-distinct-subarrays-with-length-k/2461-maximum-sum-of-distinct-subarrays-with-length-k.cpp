class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, n = nums.size(), ans = 0;
        unordered_map<long, long>mp;
        for(int high = 0, low = 0; high < n; high++) {
            mp[nums[high]]++;
            sum += nums[high];
            if(high - low + 1 > k) {
                mp[nums[low]]--;
                sum -= nums[low];
                low++;
            }
            while(mp[nums[high]] > 1) {
                mp[nums[low]]--;
                sum -= nums[low];
                low++;
            }
            if(high - low + 1 == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};