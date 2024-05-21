class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int ind, vector<int>&temp) {
        if(ind >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        for(int i=ind; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(nums, i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(nums, 0, temp);
        return ans;
    }
};