class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] == B[0] ? A[1] < B[1] : A[0] < B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1; i<n; i++) {
            if(ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};