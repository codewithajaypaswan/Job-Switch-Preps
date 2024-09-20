class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int idx = 0, n=nums.size();
        for(int i=0; i<nums.size(); i++) {
            while(nums[i] != i && nums[i]!=nums[nums[i]]) swap(nums[i], nums[nums[i]]);
        }
        return {nums[n-1], nums[n-2]};
    }
};