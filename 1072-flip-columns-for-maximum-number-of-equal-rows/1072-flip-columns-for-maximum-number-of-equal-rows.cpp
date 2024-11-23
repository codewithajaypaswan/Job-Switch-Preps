class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& M) {
		unordered_map<string, int>mp;
        for(auto m:M) {
            string s(m.size(), 'X');
            for(int i=1; i<m.size(); i++) {
                if(m[0] != m[i]) s[i] = 'Y';
            }
            mp[s]++;
        }
        int ans = 0;
        for(auto it:mp) {
            ans = max(ans, it.second);
        }
        return ans;
	}
};