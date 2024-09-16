class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool>vis(1440+1, false);
        int start = INT_MAX, end = INT_MIN;
        for(string t:timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            int time = h*60+m;
            if(vis[time]) return 0;
            vis[time] = true;
            start = min(start, time);
            end = max(end, time);
        }
        
        int minDiff = INT_MAX, prev = 0;
        for(int i=start; i<=end; i++) {
            if(vis[i]) {
                if(i == start) {
                    // min can be from two direction
                    minDiff = min({minDiff, end - start, 1440 - (end - start)});
                }
                else {
                    minDiff = min(minDiff, i - prev);
                }
                prev = i;
            }
        }
        return minDiff;
    }
};