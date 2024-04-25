class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int>left(n, 1), right(n, 1);
        for(int i=1; i<n; i++) {
            if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
        }
        for(int i=n-2; i>=0; i--) {
            if(arr[i] > arr[i+1]) right[i] = right[i+1] + 1;
        }
        for(int i=1; i<n-1; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                ans = max(ans, left[i-1] + right[i+1] + 1);
            }
        }
        return ans;
    }
};