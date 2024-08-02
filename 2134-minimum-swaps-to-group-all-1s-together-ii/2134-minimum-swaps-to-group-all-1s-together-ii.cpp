class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) cnt1++;
        }
        for(int i = 0, j = 0, oneInWindow = 0; i < n; i++) {
            // slide the window till cnt1
            while((j - i) < cnt1) {
                oneInWindow += nums[j%n];
                j++;
            }
            ans = min(ans, cnt1 - oneInWindow);
            oneInWindow -= nums[i];
        }
        return ans;
    }
};