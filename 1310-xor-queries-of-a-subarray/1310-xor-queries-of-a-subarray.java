class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] temp = new int[n+1];
        int[] ans = new int[queries.length];
        temp[0] = 0;
        for(int i=1; i<=n; i++) {
            temp[i] = temp[i-1] ^ arr[i-1];
        }
        for(int i=0; i<queries.length; i++) {
            ans[i] = temp[queries[i][0]] ^ temp[queries[i][1] + 1];
        }
        return ans;
    }
}