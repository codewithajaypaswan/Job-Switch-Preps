class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, curSum = 0, n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            curSum += nums[i];
            int rem = (curSum%k + k)%k;
            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};