class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int high = 0, low = 0, cntZero = 0; high < n; high++) {
            cntZero += nums[high] == 0 ? 1 : 0;
            while(cntZero > k) {
                cntZero -= nums[low] == 0 ? 1 : 0;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};