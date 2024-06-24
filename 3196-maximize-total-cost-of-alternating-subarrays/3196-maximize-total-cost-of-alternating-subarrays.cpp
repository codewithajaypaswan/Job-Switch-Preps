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