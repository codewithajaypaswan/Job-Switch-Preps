class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int n, int m) {
        int sz = org.size(), ind = 0;
        if(m*n != sz) return {};
        vector<vector<int>>ans(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = org[ind++];
            }
        }
        return ans;
    }
};