class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>vp;
        int n = names.size();
        for(int i=0; i<n; i++) {
            vp.push_back({heights[i], names[i]});
        }
        sort(vp.begin(), vp.end(), cmp);
        vector<string>ans;
        for(auto it:vp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    static bool cmp(pair<int, string>&A, pair<int, string>&B) {
        return A.first > B.first;
    }
};