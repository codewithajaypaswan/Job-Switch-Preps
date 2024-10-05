class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26, 0), freq2(26, 0);
        for(char c:s1) freq1[c - 'a']++;
        int n1 = s1.size(), n2 = s2.size();
        for(int low=0, high=0; high<n2; high++) {
            freq2[s2[high] - 'a']++;
            if(high - low + 1 > n1) {
                freq2[s2[low]-'a']--;
                low++;
            }
            if(freq1 == freq2) return true;
        }
        return false;
    }
};