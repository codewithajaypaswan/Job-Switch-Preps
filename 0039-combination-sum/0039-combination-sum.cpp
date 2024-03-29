class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, vector<int>&temp, int target, int ind) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<arr.size(); i++) {
            temp.push_back(arr[i]);
            solve(arr, temp, target - arr[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates, temp, target, 0);
        return ans;
    }
};