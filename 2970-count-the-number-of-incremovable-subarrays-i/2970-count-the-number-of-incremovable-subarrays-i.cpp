class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 3;
        int ans = 1;
        int left = 0, right = n-1;
        // delete from the front
        while(left+1 < n && nums[left] < nums[left+1]) {
            left++;
        }
        ans += left + 1;
        // delete from the end
        while(right > 0 && nums[right-1] < nums[right]) {
            right--;
        }
        ans += n - right;
        // best case to delete all the numbers
        if(left >= right) {
            return (n * (n+1))/2;
        }
        // detele from the middle
        left = 0;
        while(left < right && right < n && left < n) {
            if(nums[left] < nums[right]) {
                // delete
                ans += right == n-1 ? 1 : n - right;
                if(left + 1 < n && nums[left] < nums[left+1]) left++;
                else break;
            }
            else {
                right++;
            }
        }
        return ans;
    }
};