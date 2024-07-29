class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxJump = nums[0];
        for(int i=1; i<n; i++) {
            if(i > maxJump) return false;
            maxJump = max(maxJump, nums[i] + i);
        }
        return true;
    }
};

/*


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[0] = 1;
        for(int i=1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(nums[j] + j >= i && dp[j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
*/