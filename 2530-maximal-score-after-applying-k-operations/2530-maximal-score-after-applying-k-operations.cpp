class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans = 0;
        for(int x:nums) pq.push(x);
        while(!pq.empty() && k--) {
            int x = pq.top(); pq.pop();
            ans += x;
            x = ceil((double)x / 3);
            if(x > 0) pq.push(x);
        }
        return ans;
    }
};