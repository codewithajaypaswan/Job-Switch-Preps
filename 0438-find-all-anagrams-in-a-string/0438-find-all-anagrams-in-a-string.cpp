class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int>hashS(26, 0), hashP(26, 0);
        vector<int>ans;
        if(m > n) return ans;
        for(int i=0; i<m; i++) {
            hashP[p[i] - 'a']++;
        }
        for(int high = 0, low = 0; high < n; high++) {
            hashS[s[high] - 'a']++;
            if(high - low + 1 == m) {
                if(hashS == hashP) ans.push_back(low);
                hashS[s[low++] - 'a']--;
            }
        }
        return ans;
    }
};