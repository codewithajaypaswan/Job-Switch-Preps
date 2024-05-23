class Solution {
public:
    unordered_map<int, int>mp;
    int solve(vector<int>&nums, int k, int ind) {
        if(ind == nums.size()) return 1;
        int ans = solve(nums, k, ind+1); // when skip
        if(mp[nums[ind] - k] == 0) {
            mp[nums[ind]]++; // take this nums[i]
            ans += solve(nums, k, ind+1);
            mp[nums[ind]]--; // revert this nums[i]
        }
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return solve(nums, k, 0) - 1;
    }
};