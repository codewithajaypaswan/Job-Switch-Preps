class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cntZero = 0, prod = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) cntZero++;
            else prod *= nums[i];
        }
        vector<int>ans;
        for(int x:nums) {
            if(cntZero >= 2) {
                ans.push_back(0);
            }
            else if(x != 0 && cntZero == 1) {
                ans.push_back(0);
            }
            else if(x == 0 && cntZero == 1) {
                ans.push_back(prod);
            }
            else {
                ans.push_back(prod/x);
            }
        }
        return ans;
    }
};