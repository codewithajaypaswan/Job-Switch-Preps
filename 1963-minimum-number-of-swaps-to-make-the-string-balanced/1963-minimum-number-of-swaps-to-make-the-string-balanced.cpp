class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), ans = 0, cnt = 0;
        vector<int>left;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == ']') left.push_back(i);
        }
        int pos = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '[') cnt++;
            else cnt--;
            if(cnt < 0) {
                swap(s[i], s[pos]);
                pos++;
                cnt = 1;
                ans++;
            }
        }
        return ans;
    }
};