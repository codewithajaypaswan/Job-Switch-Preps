class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1; i<=9; i++) q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(cur >= low && cur <= high) {
                ans.push_back(cur);
            }
            if(cur%10 == 9) continue;
            q.push(cur*10 + (cur%10) + 1);
        }
        return ans;
    }
};