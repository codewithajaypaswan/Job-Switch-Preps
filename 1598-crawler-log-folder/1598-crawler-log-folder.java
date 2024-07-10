class Solution {
    public int minOperations(String[] logs) {
        int cnt = 0;
        for(String s:logs) {
            if(s.charAt(1) == '.' && cnt != 0) cnt--;
            if(s.charAt(0) != '.') cnt++;
        }
        return cnt;
    }
}