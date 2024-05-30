class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int cnt = 0, n = nums.size();
        vector<int>vis(n+1, -1);
        for(int i=0; i<n; i++) {
            if(nums[i] == x) cnt++;
            if(cnt && vis[cnt] == -1) vis[cnt] = i;
        }
        vector<int>ans;
        for(int q:queries) {
            if(q > n) ans.push_back(-1);
            else ans.push_back(vis[q]);
        }
        return ans;
    }
};