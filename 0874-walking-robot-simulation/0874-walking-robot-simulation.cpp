class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, ans = 0;
        set<pair<int, int>>st;
        for(auto v:obstacles) {
            st.insert({v[0], v[1]});
        }
        int dir = 0;
        for(auto c:commands) {
            if(c == -1) {
                dir = (dir + 1)%4;
            }
            else if(c == -2) {
                dir = (dir - 1 + 4)%4;
            }
            else {
                while(c-- && st.find({dx[dir] + x, dy[dir] + y}) == st.end()) {
                    x += dx[dir];
                    y += dy[dir];
                }
                ans = max(ans, x*x + y*y);
            }
        }
        return ans;
    }
};