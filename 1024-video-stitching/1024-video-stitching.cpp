class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        vector<int>dp(101, 101);
        dp[0] = 0;
        for(int i=0; i<clips.size(); i++) {
            int start = clips[i][0];
            int end = clips[i][1];
            for(int i=start+1; i<=end; i++) {
                dp[i] = min(dp[i], dp[start] + 1);
            }
        }
        return dp[time] == 101 ? -1 : dp[time];
    }
};