class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftPar = 0, rightPar = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') leftPar++;
            else if(leftPar) leftPar--;
            else rightPar++;
        }
        return leftPar + rightPar;
    }
};