class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n, 0), right(n, 0);
        left[0] = arr[0];
        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1], arr[i]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = min(right[i+1], arr[i]);
        }
        int chunk = 1;
        for(int i=0; i<n-1; i++) {
            if(left[i] <= right[i+1]) chunk++;
        }
        return chunk;
    }
};