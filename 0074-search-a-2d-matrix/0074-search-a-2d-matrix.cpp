class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m*n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int val = mat[mid/m][mid%m];
            if(val == target) return true;
            else if(val < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return false;
    }
};