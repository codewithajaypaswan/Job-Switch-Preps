class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        for(int i=1; i<arr.size(); i++) {
            arr[i] ^= arr[i-1];
        }
        int ans = 0, n = arr.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(arr[i] == arr[j]) ans += j-i-1;
            }
        }
        return ans;
    }
};