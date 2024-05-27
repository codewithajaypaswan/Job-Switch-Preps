class Solution {
public:
    int noOfElementGreaterThan(vector<int>&nums, int temp) {
        int low = 0, high = nums.size()-1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= temp) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<=n; i++) {
            int k = noOfElementGreaterThan(nums, i);
            if(n - k == i) return i;
        }
        return -1;
    }
};