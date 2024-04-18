class Solution {
public:
    bool check(int cap, int low, int high, vector<int>&weights, int days_cnt) {
        int day = 1, sum = 0;
        for(int w:weights) {
            if(w + sum > cap) {
                day++;
                sum = w;
            }
            else {
                sum += w;
            }
        }
        return day <= days_cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long low = 0, high = 0;
        for(int w:weights) {
            high += w;
            low = max(1L * w, low);
        }
        int ans = -1;
        while(low <= high) {
            long mid = low + (high - low)/2;
            if(check(mid, low, high, weights, days)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};