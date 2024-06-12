class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int>left(n), right(n);
        left[n-1] = s[n-1] == 'L' ? n : 0;
        for(int i=n-2; i>=0; i--) {
            if(s[i] == 'L') left[i] = n;
            else if(s[i] == 'R') left[i] = 0;
            else left[i] = max(0, left[i+1] - 1);
        }
        right[0] = s[0] == 'R' ? n : 0;
        for(int i=1; i<n; i++) {
            if(s[i] == 'R') right[i] = n;
            else if(s[i] == 'L') right[i] = 0;
            else right[i] = max(0, right[i-1] - 1);
        }
        for(int i=0; i<n; i++) {
            if(left[i] > right[i]) s[i] = 'L';
            else if(left[i] < right[i]) s[i] = 'R';
            else s[i] = '.';
        }
        return s;
    }
};