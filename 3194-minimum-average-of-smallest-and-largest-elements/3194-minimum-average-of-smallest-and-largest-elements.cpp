class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        double ans = INT_MAX;
        while(i < j) {
            double val = (double)(nums[i] + nums[j])/2;
            ans = min(ans, val);
            i++; j--;
        }
        return ans;
    }
};