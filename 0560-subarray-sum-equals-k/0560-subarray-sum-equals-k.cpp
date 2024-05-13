class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i=0, sum = 0; i<n; i++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};