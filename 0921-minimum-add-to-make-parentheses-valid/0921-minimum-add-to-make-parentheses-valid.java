class Solution {
    public int minAddToMakeValid(String s) {
        int leftPar = 0, rightPar = 0;
        for(char c:s.toCharArray()) {
            if(c == '(') leftPar++;
            else if(c == ')') {
                if(leftPar > 0) leftPar--;
                else rightPar++;
            }
        }
        return leftPar + rightPar;
    }
}