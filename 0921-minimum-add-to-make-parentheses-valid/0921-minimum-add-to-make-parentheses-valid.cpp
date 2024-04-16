class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftPar = 0, rightPar = 0;
        for(char c:s) {
            if(c == '(') leftPar++;
            else if(leftPar) leftPar--;
            else rightPar++;
        }
        return leftPar + rightPar;
    }
};