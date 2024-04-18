class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>res(2, -1);
        int flag = 0, ans = -1, low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target && (flag == 0 || mid <= ans)) {
                ans = mid;
                high = mid-1;
                flag = 1;
            }
            else if(nums[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        if(flag == 0) return res;
        res[0] = ans;
        low = ans;
        high = n-1;
        flag = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target && (flag == 0 || mid >= ans)) {
                ans = mid;
                low = mid+1;
                flag = 1;
            }
            else if(nums[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        res[1] = ans;
        return res;
    }
};