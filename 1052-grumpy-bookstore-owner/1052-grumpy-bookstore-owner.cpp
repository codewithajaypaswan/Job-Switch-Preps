class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int minutes) {
        int n = c.size(), sum = 0;
        for(int i=0; i<n; i++) {
            if(g[i] == 0) sum += c[i];
        }
        int slidingSum = 0;
        for(int high = 0, low = 0, temp = 0; high < n; high++) {
            if(g[high] == 1) temp += c[high];
            if(high - low + 1 == minutes) {
                slidingSum = max(slidingSum, temp);
                if(g[low] == 1) temp -= c[low];
                low++;
            }
        }
        return sum + slidingSum;
    }
};