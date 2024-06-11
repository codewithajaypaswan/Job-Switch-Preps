class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k, int target, vector<int>&temp, int cur) {
        if(k == 0 && target == 0) {
            ans.push_back(temp);
            return;
        }
        if(k < 0 || target < 0) return;
        for(int i=cur; i<=9; i++) {
            temp.push_back(i);
            solve(k-1, target - i, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k, n, temp, 1);
        return ans;
    }
};