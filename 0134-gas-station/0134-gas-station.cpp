class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, ans = 0, balance = 0, n = gas.size();
        for(int i=0; i<n; i++) {
            int need = gas[i] - cost[i];
            total += need;
            balance += need;
            if(balance < 0) {
                ans = i+1;
                balance = 0;
            }
        }
        return total < 0 ? -1 : ans;
    }
};