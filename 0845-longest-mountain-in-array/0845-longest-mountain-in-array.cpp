class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int inc = 0, dec = 0, n = arr.size();
        int i = 1, ans = 0;
        while(i < n) {
            inc = 0, dec = 0;
            while(i < n && arr[i-1] < arr[i]) i++, inc++;
            while(i < n && arr[i-1] > arr[i]) i++, dec++;
            if(inc && dec) {
                ans = max(ans, inc + dec + 1);
            }
            while(i < n && arr[i-1] == arr[i]) i++;
        }
        return ans;
    }
};