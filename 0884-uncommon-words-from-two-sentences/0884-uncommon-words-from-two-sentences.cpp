class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>mp;
        istringstream ss(s1 + " " + s2);
        while(ss >> s1) {
            mp[s1]++;
        }
        for(auto it:mp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};