class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int>prefix(n, 0), suffix(n, 0);
        for(int i=0, j = 0; i<n && j < m; i++) {
            if(s[i] == t[j]) {
                prefix[i]++;
                j++;
            }
            if(i > 0) prefix[i] += prefix[i-1];
        }
        for(int i=n-1, j = m-1; i>=0 && j >= 0; i--) {
            if(s[i] == t[j]) {
                suffix[i]++;
                j--;
            }
            if(i < n-1) suffix[i] += suffix[i+1];
        }
        // now my prefix contains all the matching subsequece of t from the prefix
        // sufix contains all the matching subsequence of s from suffix
        int ans = INT_MAX;
        for(int i=0; i<n-1; i++) {
            ans = min(ans, m - (suffix[i+1] + prefix[i]));
        }
        ans = min(ans, m - suffix[0]);
        ans = min(ans, m - prefix[n-1]);
        return max(0, ans);
    }
};