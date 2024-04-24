class Solution {
public:
    int n;
    int VISITED = 1, VISITING = 2, NOT_VISITED = 0;
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        vector<int>vis(n, NOT_VISITED);
        for(int i=0; i<n; i++) {
            if(vis[i] == NOT_VISITED && dfs(nums, i, vis)) return true;
        }
        return false;
    }
    bool dfs(vector<int>&nums, int cur, vector<int>&vis) {
        if(vis[cur] == VISITED) return false;
        if(vis[cur] == VISITING) return true;
        vis[cur] = VISITING;
        int next = (cur + nums[cur])%n;
        if(next < 0) next += n;
        if(cur == next || nums[cur] * nums[next] < 0) {
            vis[cur] = VISITED;
            return false;
        }
        if(dfs(nums, next, vis)) return true;
        vis[cur] = VISITED;
        return false;
    }
};