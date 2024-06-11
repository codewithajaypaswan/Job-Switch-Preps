class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, int target, int cur, vector<int>&temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0 || cur >= arr.size()) return;
        unordered_set<int>st;
        for(int i=cur; i<arr.size(); i++) {
            if(st.find(arr[i]) != st.end()) continue;
            st.insert(arr[i]);
            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp);
        return ans;
    }
};