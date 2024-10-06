class Solution {
public:
    vector<string> split(string &str) {
        vector<string>ans;
        str += ' ';
        string s = "";
        for(char c:str) {
            if(c == ' ') {
                ans.push_back(s);
                s = "";
            }
            else {
                s += c;
            }
        }
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>s1 = split(sentence1);
        vector<string>s2 = split(sentence2);
        if(s1.size() < s2.size()) swap(s1, s2);
        int start = 0, end = 0;
        while(start < s2.size() && s1[start] == s2[start]) start++;
        while(end < s2.size() && s2[s2.size() - 1 - end] == s1[s1.size() - 1 - end]) end++;
        return start + end >= s2.size();
    }
};