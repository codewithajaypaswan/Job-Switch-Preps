class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool>vis(n, false);
        for(int i=0; i<n; i++) {
            if(vis[i] == true) continue;
            int cnt = 0;
            while(vis[i] == false) {
                vis[i] = true;
                cnt++;
                i = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};