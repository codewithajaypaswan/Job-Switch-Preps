class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long ans = 0;
        for(auto g:gifts) {
            pq.push(g);
        }
        while(k--) {
            int x = pq.top(); pq.pop();
            pq.push(sqrt(x));
        }
        while(!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
        return ans;
    }
};