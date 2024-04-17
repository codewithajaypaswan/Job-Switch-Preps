class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;
        vector<int>bit(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<words[i].size(); j++) {
                bit[i] |= 1<<(words[i][j] - 'a');
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(!(bit[i]&bit[j])) {
                    ans = max(ans, (int) (words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};