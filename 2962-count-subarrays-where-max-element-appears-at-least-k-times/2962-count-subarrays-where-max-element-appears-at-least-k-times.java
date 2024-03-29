class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for(long long high = 0, low = 0, count = 0; high < nums.size(); high++) {
            if(nums[high] == mx) count++;
            while(count >= k) {
                if(nums[low] == mx) count--;
                ans += (nums.size() - high);
                low++;
            }
        }
        return ans;
    }
};