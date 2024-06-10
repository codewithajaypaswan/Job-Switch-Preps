class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        bitset<100001>dp, mask, validPrev;
        sort(rewardValues.begin(), rewardValues.end());
        dp[0] = 1;
        int maskId = 0;
        for(int val:rewardValues) {
            while(maskId < val) mask[maskId++] = 1;
            validPrev = (dp & mask);
            dp = dp|(validPrev << val);
        }
        int ans = 1e5;
        while(dp[ans] == 0) ans--;
        return ans;
    }
};