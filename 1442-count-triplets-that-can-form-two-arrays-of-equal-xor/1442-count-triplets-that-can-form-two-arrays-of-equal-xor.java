class Solution {
    public int countTriplets(int[] arr) {
        int n = arr.length, ans = 0;
        int[] prefixXor = new int[n+1];
        prefixXor[0] = 0;
        for(int i=1; i<=n; i++) {
            prefixXor[i] = arr[i-1] ^ prefixXor[i-1];
        }
        for(int i=0; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                if((prefixXor[i] ^ prefixXor[j]) == 0) ans += j-i-1;
            }
        }
        return ans;
    }
}