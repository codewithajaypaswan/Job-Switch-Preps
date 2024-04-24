class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == -1) continue;
            int cnt = 0, cur = i;
            while(nums[cur] != -1) {
                int next = nums[cur];
                nums[cur] = -1;
                cur = next;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};