class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long need = 0, sum = 0, ans = INT_MAX;
        for(int x:nums) {
            need = (need + x)%p;
        }
        if(need == 0) return 0;
        unordered_map<long, long>mp;
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum = (sum + nums[i])%p;
            long want = (sum - need + p)%p;
            if(mp.find(want) != mp.end()) {
                ans = min(ans, i - mp[want]);
            }
            mp[sum] = i;
        }
        return ans >= n ? -1 : ans;
    }
};