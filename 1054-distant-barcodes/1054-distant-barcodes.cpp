class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int>mp;
        for(int x:barcodes) mp[x]++;
        priority_queue<pair<int, int>>pq;
        for(auto it:mp) {
            pq.push({it.second, it.first});
        }
        int i = 0, n = barcodes.size();
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int val = it.second, cnt = it.first;
            while(cnt--) {
                if(i >= n) i = 1;
                barcodes[i] = val;
                i+=2;
            }
        }
        return barcodes;
    }
};