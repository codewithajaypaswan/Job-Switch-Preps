class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), index_sum = 0, arr_sum = 0;
        int ans = 0;
        for(int i=0; i<n; i++) {
            index_sum += i;
            arr_sum += arr[i];
            if(index_sum == arr_sum) ans++;
        }
        return ans;
    }
};