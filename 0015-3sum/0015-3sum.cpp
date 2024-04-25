class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int n1 = nums[i];
            int front = i+1, back = n-1;
            while(front < back) {
                int target = nums[i] + nums[front] + nums[back];
                if(target > 0) {
                    back--;
                }
                else if(target < 0) {
                    front++;
                }
                else {
                    vector<int> res = {nums[i], nums[front], nums[back]};
                    ans.push_back(res);
                    while(front < back && nums[front] == res[1]) front++;
                    while(front < back && nums[back] == res[2]) back--;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};