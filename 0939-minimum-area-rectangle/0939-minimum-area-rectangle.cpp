class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>>mp;
        int n = points.size(), ans = INT_MAX;
        for(auto p:points) {
            mp[p[0]].insert(p[1]);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 || y1 == y2) continue;
                if(mp[x1].find(y2) != mp[x1].end() && mp[x2].find(y1) != mp[x2].end()) {
                    ans = min(ans, abs(x2 - x1) * abs(y2 - y1));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};