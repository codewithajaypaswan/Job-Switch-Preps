class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long inc = 0, dec = 0, ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            long long diff = nums[i] - target[i];
            if(diff > 0) {
                if(inc < diff) {
                    ans += diff - inc;
                }
                inc = diff;
                dec = 0;
            }
            else if(diff < 0) {
                if(dec < abs(diff)) {
                    ans += abs(diff) - dec;
                }
                dec = abs(diff);
                inc = 0;
            }
            else {
                inc = dec = 0;
            }
        }
        return ans;
    }
};