class Solution {
public:
    int findMax(vector<int>&arr, int k) {
        set<int>st;
        st.insert(0);
        int ans = INT_MIN;
        int prefix_sum = 0;
        for(int i=0; i<arr.size(); i++) {
            prefix_sum += arr[i];
            // find the element in the set which is larger than or equal to (prefixSum - k) in the set
            auto it = st.lower_bound(prefix_sum - k);
            if(it != st.end()) {
                ans = max(ans, prefix_sum - *it);
            }
            st.insert(prefix_sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            vector<int>col(m, 0);
            for(int r=i; r<n; r++) {
                for(int c=0; c<m; c++) 
                    col[c] += mat[r][c];
                ans = max(ans, findMax(col, k));
            }
        }
        return ans;
    }
};