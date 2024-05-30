class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool vowel = false, constanant = false;
        for(char c:word) {
            if(!isdigit(c) && !isalpha(c)) return false;
            if(isVowel(c)) {
                vowel = true;
            }
            else if(isalpha(c)) {
                constanant = true;
            }
        }
        return vowel && constanant;
    }
};