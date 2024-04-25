class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs[strs.size()-1];
        for(int i=0; i<min(a.size(), b.size()); i++) {
            if(a[i] != b[i]) {
                return a.substr(0, i);
            }
        }
        return a.size() < b.size() ? a : b;
    }
};