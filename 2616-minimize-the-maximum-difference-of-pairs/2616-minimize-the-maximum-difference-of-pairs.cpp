class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = -1;
        int low = 0, high = nums[n-1] - nums[0];
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
    bool check(int mid, vector<int>&nums, int p) {
        int cnt = 0;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i+1] - nums[i] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
};