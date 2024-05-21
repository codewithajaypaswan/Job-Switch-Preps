class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix;
        prefix.push_back(0);
        for(int i=1, j = 0; i < n; i++) {
            if(nums[i]%2 == nums[i-1]%2) j++;
            prefix.push_back(j);
        }
        vector<bool>ans;
        for(vector<int>q: queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefix[l] == prefix[r]);
        }
        return ans;
    }
};