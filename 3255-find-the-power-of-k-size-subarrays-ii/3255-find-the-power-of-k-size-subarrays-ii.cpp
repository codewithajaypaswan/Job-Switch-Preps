class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0, score = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]+1) score++;
            else score = 0;
            if(i >= k-1) {
                if(score >= k-1) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};