class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B) {
        return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), cmp);
        int n = env.size();
        vector<int>ans;
        ans.push_back(env[0][1]);
        for(int i=1; i<n; i++) {
            if(ans.back() < env[i][1]) {
                ans.push_back(env[i][1]);
            }
            else {
                int ind = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[ind] = env[i][1];
            }
        }
        return ans.size();
    }
};