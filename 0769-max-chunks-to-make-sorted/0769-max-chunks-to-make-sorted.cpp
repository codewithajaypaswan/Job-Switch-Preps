class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for(int i=0, sum = 0, index_sum; i<n; i++) {
            sum += arr[i];
            index_sum += i;
            if(index_sum == sum) ans++;
        }
        return ans;
    }
};