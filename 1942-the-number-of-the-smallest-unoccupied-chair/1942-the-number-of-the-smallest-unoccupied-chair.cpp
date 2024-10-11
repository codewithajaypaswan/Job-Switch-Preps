class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>busy; // endTime, index;
        priority_queue<int, vector<int>, greater<int>>free; // index currently available
        int n = times.size();
        for(int i=0; i<n; i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        int newChair = 0;
        for(int i=0; i<n; i++) {
            int arrival = times[i][0];
            int leave = times[i][1];
            int index = times[i][2];
            while(!busy.empty() && busy.top().first <= arrival) {
                free.push(busy.top().second);
                busy.pop();
            }
            if(free.empty()) {
                if(index == targetFriend) return newChair;
                busy.push({leave, newChair});
                newChair++;
            }
            else {
                int x = free.top(); free.pop();
                if(index == targetFriend) return x;
                busy.push({leave, x});
            }
        }
        return -1;
    }
};