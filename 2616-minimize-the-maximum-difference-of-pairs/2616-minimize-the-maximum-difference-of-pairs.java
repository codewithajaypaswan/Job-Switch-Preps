class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length, ans = -1;
        int high = nums[n-1] - nums[0], low = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid, nums, p)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    boolean check(int mid, int[] nums, int p) {
        int cnt = 0;
        for(int i=0; i<nums.length-1; i++) {
            if(nums[i+1] - nums[i] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
}