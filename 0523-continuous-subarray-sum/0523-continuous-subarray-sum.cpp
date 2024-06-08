class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long prefix = 0, n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            prefix = (prefix + nums[i])%k;
            if(mp.find(prefix) != mp.end()) {
                if(i - mp[prefix] >= 2) return true;
            }
            else mp[prefix] = i;
        }
        return false;
    }
};