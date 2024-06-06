class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mp;
        for(int x:hand) mp[x]++;
        for(auto it:mp) {
            int freq = it.second, val = it.first;
            if(freq > 0) {
                for(int i=0; i<groupSize; i++) {
                    mp[val + i] -= freq;
                    if(mp[val + i] < 0) return false;
                }
            }
        }
        return true;
    }
};