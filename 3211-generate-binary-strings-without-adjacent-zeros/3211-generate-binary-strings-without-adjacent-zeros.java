class Solution {
    List<String>ans = new ArrayList<>();
    public List<String> validStrings(int n) {
        StringBuilder temp = new StringBuilder();
        solve(n, temp);
        return ans;
    }
    void solve(int n, StringBuilder sb) {
        if(n == 0) {
            ans.add(sb.toString());
            return;
        }
        if(sb.isEmpty()) {
            solve(n-1, new StringBuilder(sb).append('0'));
            solve(n-1, new StringBuilder(sb).append('1'));
        }
        else if(sb.charAt(sb.length()-1) == '1') {
            solve(n-1, new StringBuilder(sb).append('0'));
            solve(n-1, new StringBuilder(sb).append('1'));
        }
        else {
            solve(n-1, new StringBuilder(sb).append('1'));
        }
    }
}