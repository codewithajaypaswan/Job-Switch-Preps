class Solution {
public:
    long long solve(vector<int>&nums, int val) {
        long long ans = 0;
        for(int low = 0, high = nums.size()-1; low < high; low++) {
            while(low < high && nums[high] + nums[low] > val) {
                high--;
            }
            ans += high - low;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return solve(nums, upper) - solve(nums, lower-1);
    }
};