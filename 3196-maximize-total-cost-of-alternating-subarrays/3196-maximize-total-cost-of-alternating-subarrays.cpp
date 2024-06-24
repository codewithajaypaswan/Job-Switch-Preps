class Solution {
public:
    #define ll long long
    long long maximumTotalCost(vector<int>& nums) {
        ll addResult = nums[0], subResult = nums[0];
        for(int i=1; i<nums.size(); i++) {
            ll tempAddResult = max(addResult, subResult) + nums[i];
            ll tempSubResult = addResult - nums[i];
            addResult = tempAddResult;
            subResult = tempSubResult;
        }
        return max(addResult, subResult);
    }
};

/*
sol - 2
class Solution {
public:
    #define ll long long
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>dp(n, vector<ll>(3, INT_MAX));
        return solve(nums, 0, dp, 0);
    }
    long long solve(vector<int>&nums, int cur, vector<vector<ll>>&dp, int flag) {
        if(cur >= nums.size()) return 0;
        if(dp[cur][flag] != INT_MAX) return dp[cur][flag];
        ll noFlip = nums[cur] + solve(nums, cur+1, dp, 1);
        ll flip = 0;
        if(flag == 1) {
            flip += (-nums[cur]) + solve(nums, cur+1, dp, 0);
        }
        else {
            flip += nums[cur] + solve(nums, cur+1, dp, 1);
        }
        // cout<<flip<<" "<<noFlip<<endl;
        return dp[cur][flag] = max(flip, noFlip);
    }
};
*/