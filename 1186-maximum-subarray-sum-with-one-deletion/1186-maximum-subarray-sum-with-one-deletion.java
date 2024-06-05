class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int ans = Math.max(arr[0], arr[n-1]);
        left[0] = arr[0];
        for(int i=1; i<n; i++) {
            left[i] = Math.max(left[i-1] + arr[i], arr[i]);
            ans = Math.max(ans, left[i]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = Math.max(right[i+1] + arr[i], arr[i]);
            ans = Math.max(ans, right[i]);
        }
        for(int i=1; i<n-1; i++) {
            ans = Math.max(ans, left[i-1] + right[i+1]);
        }
        return ans;
    }
}