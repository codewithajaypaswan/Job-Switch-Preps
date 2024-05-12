class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) {
            vector<int>freq(26, 0);
            for(char c:s) freq[c - 'a']++;
            for(int i=0; i<26; i++) {
                if(freq[i] >= 2) return true;
            }
        }
        else {
            int x = -1;
            for(int i=0; i<s.size(); i++) {
                if(s[i] != goal[i]) {
                    if(x == -1) x = i;
                    else {
                        swap(s[i], s[x]);
                        return s == goal;
                    }
                }
            }
        }
        return false;
    }
};