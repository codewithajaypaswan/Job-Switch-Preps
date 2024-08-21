class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<=n-k; i++) {
            int flag = 0;
            for(int j=i+1; j<i+k; j++) {
                if(nums[j-1]+1 != nums[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag) ans.push_back(-1);
            else ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};