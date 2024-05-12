class Solution {
public:
    bool check(vector<int>&freq1, vector<int>&freq2) {
        for(int i=0; i<26; i++) {
            if(freq1[i] < freq2[i]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>freq2(26, 0);
        for(string str:words2) {
            vector<int>temp(26, 0);
            for(char c:str) {
                temp[c - 'a']++;
                freq2[c - 'a'] = max(freq2[c - 'a'], temp[c - 'a']);
            }
        }
        for(string str:words1) {
            vector<int>freq1(26, 0);
            for(char c:str) {
                freq1[c - 'a']++;
            }
            if(check(freq1, freq2)) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};