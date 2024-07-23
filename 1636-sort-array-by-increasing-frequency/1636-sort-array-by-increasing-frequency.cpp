class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>>vp;
        unordered_map<int, int>mp;
        for(int x:nums) {
            mp[x]++;
        }
        for(auto it:mp) {
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end(), cmp);
        vector<int>ans;
        for(int i=0; i<vp.size(); i++) {
            while(vp[i].first) {
                ans.push_back(vp[i].second);
                vp[i].first--;
            }
        }
        return ans;
    }
    static bool cmp(pair<int, int>&A, pair<int, int>&B) {
        return A.first == B.first ? A.second > B.second : A.first < B.first;
    }
};