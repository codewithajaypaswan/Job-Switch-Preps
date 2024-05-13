class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int sum = 0, ans = 0;
        mp[sum] = -1;
        for(int i=0; i<n; i++) {
            int x = nums[i] == 0 ? -1 : 1;
            sum += x;
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};