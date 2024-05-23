class Solution {
public:
    unordered_map<int, int>mp;
    int ans = 0;
    int solve(vector<int>&nums, int k, int ind, int mask) {
        if(ind == nums.size()){
            return 1;
        }
        bool include = true;
        int ans = 0;
        for(int i=0; i<ind; i++) {
            if(mask&(1<<i)) {
                if(abs(nums[i] - nums[ind]) == k) {
                    include = false;
                    break;
                }
            }
        }
        if(include) ans += solve(nums, k, ind+1, mask|(1<<ind));
        ans += solve(nums, k, ind+1, mask);
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        return solve(nums, k, 0, 0) - 1;
        return ans;
    }
};