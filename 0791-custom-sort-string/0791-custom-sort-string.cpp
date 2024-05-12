class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        for(char x:s) {
            mp[x]++;
        }
        string ans = "";
        for(char x:order) {
            ans += string(mp[x], x);
            mp[x] = 0;
        }
        for(auto it:mp) {
            ans += string(it.second, it.first);
        }
        return ans;
    }
};