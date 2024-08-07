class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int>hashS(26, 0), hashP(26, 0);
        vector<int>ans;
        if(m > n) return ans;
        for(int i=0; i<m; i++) {
            hashS[s[i] - 'a']++;
            hashP[p[i] - 'a']++;
        }
        int windowStart = 0, windowEnd = m;
        while(windowEnd < n) {
            if(hashS == hashP) {
                ans.push_back(windowStart);
            }
            hashS[s[windowStart++] - 'a']--;
            hashS[s[windowEnd++] - 'a']++;
        }
        if(hashS == hashP) {
            ans.push_back(windowStart);
        }
        return ans;
    }
};