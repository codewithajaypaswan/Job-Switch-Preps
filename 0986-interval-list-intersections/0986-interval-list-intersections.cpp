class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> intervalIntersection(vector<vector<int>>&A, vector<vector<int>>& B) {
        int n = A.size(), m = B.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(A[i][1] < B[j][0]) {
                i++;
            }
            else if(B[j][1] < A[i][0]) {
                j++;
            }
            else {
                int start = max(A[i][0], B[j][0]);
                int end = min(A[i][1], B[j][1]);
                ans.push_back({start, end});
                if(A[i][1] < B[j][1]) i++;
                else j++;
            }
        }
        return ans;
    }
};