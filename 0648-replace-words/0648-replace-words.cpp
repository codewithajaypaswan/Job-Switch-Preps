class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>mp;
        for(string s:dictionary) {
            mp.insert(s);
        }
        sentence += " ";
        string ans = "";
        for(int i=0; i<sentence.size(); i++) {
            string word = "";
            while(sentence[i] != ' ') {
                word += sentence[i];
                i++;
                if(mp.count(word)) {
                    while(sentence[i] != ' ') i++;
                }
            }
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};