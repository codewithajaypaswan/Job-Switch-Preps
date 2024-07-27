class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>mp;
        for(int i=0; i<e.size(); i++) {
            mp[e[i][0]].push_back({e[i][1], values[i]});
            mp[e[i][1]].push_back({e[i][0], 1/values[i]});
        }
        vector<double>ans;
        for(auto q:queries) {
            string src = q[0], dest = q[1];
            double res = -1.0, cur = 1.0;
            unordered_set<string>st;
            dfs(st, mp, res, cur, src, dest);
            ans.push_back(res);
        }
        return ans;
    }
    void dfs(unordered_set<string>&st, unordered_map<string, vector<pair<string, double>>>&mp, double &res, double cur, string src, string dest) {
        if(st.count(src)) return;
        if(mp[src].size() == 0) return;
        if(src == dest) {
            res = cur;
            return;
        }
        st.insert(src);
        for(auto it:mp[src]) {
            dfs(st, mp, res, cur * it.second, it.first, dest);
        }
    }
};