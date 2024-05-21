class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int ind, vector<int>&temp) {
        if(ind >= nums.size()) return;
        temp.push_back(nums[ind]);
        ans.push_back(temp);
        solve(nums, ind+1, temp);
        temp.pop_back();
        solve(nums, ind+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        ans.push_back(temp);
        solve(nums, 0, temp);
        return ans;
    }
};