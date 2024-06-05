class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>>bucket(26);
        vector<int>remove(n, 0);
        for(int i=0; i<n; i++) {
            
            if(s[i] == '*') {
                remove[i] = 1;
                for(int j=0; j<26; j++) {
                    if(bucket[j].size() > 0) {
                        remove[bucket[j].back()] = 1;
                        bucket[j].pop_back();
                        break;
                    }
                }
            }
            
            else {
                bucket[s[i] - 'a'].push_back(i);
            }
        }
        string ans = "";
        for(int i=0; i<n; i++) {
            if(remove[i] == 0) ans += s[i];
        }
        return ans;
    }
};
