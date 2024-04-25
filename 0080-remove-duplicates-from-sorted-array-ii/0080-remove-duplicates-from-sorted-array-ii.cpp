class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), ind = 0;
        for(int i=0; i<n; i++) {
            if(ind < 2 || nums[i] != nums[ind-2]) {
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};