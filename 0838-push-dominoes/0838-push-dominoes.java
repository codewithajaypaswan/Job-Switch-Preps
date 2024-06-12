class Solution {
    public String pushDominoes(String s) {
        int n = s.length();
        int[] left = new int[n];
        int[] right = new int[n];
        
        left[n-1] = s.charAt(n-1) == 'L' ? n : 0;
        for(int i=n-2; i>=0; i--) {
            if(s.charAt(i) == 'L') left[i] = n;
            else if(s.charAt(i) == 'R') left[i] = 0;
            else left[i] = Math.max(0, left[i+1] - 1);
        }
        
        right[0] = s.charAt(0) == 'R' ? n : 0;
        for(int i=1; i<n; i++) {
            if(s.charAt(i) == 'R') right[i] = n;
            else if(s.charAt(i) == 'L') right[i] = 0;
            else right[i] = Math.max(0, right[i-1] - 1);
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++) {
            if(left[i] > right[i]) sb.append('L');
            else if(left[i] < right[i]) sb.append('R');
            else sb.append('.');
        }
        return sb.toString();
    }
}