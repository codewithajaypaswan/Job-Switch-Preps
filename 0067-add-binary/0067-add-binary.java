class Solution {
    public String addBinary(String a, String b) {
        StringBuilder ans = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, num = 0;
        while(i >= 0 || j >= 0 || num == 1) {
            num += i>=0 ? (int)(a.charAt(i) - '0') : 0;
            num += j>=0 ? (int)(b.charAt(j) - '0') : 0;
            ans.append(num%2);
            num = num/2;
            i--;
            j--;
        }
        
        return ans.reverse().toString();
    }
}