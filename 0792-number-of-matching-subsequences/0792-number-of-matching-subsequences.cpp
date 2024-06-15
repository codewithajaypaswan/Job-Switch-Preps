class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(26);
        for(int i=0; i<s.size(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(string w:words) {
            int curIndex = -1, found = 1;
            for(char c:w) {
                auto it = upper_bound(v[c - 'a'].begin(), v[c - 'a'].end(), curIndex);
                if(it == v[c - 'a'].end()) {
                    found = 0;
                    break;
                }
                curIndex = *it;
            }
            if(found) ans++;
        }
        return ans;
    }
};