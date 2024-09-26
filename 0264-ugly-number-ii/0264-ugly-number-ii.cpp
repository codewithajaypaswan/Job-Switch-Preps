class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>>pq;
        pq.push(1L);
        for(int i=1; i<n; i++) {
            auto it = pq.top(); pq.pop();
            while(!pq.empty() && it == pq.top()) {
                pq.pop();
            }
            pq.push(it * 2);
            pq.push(it * 3);
            pq.push(it * 5);
        }
        return pq.top();
    }
};

/*
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i=1; i<n; i++) {
            int mn = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
            if(mn == dp[p2] * 2) {
                p2++;
            }
            if(mn == dp[p3] * 3) {
                p3++;
            }
            if(mn == dp[p5] * 5) {
                p5++;
            } 
            dp[i] = mn;
        }
        return dp[n-1];
    }
};
*/