class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(int x:happiness) {
            pq.push(x);
        }
        int cnt = 0;
        while(!pq.empty() && k--) {
            int cur = pq.top() - cnt; pq.pop();
            if(cur <= 0) return ans;
            ans += cur;
            cnt++;
        }
        return ans;
    }
};