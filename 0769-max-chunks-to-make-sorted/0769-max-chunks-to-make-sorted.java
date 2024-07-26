class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int []left = new int[n]; 
        int []right = new int[n];
        left[0] = arr[0];
        for(int i=1; i<n; i++) {
            left[i] = Math.max(arr[i], left[i-1]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = Math.min(arr[i], right[i+1]);
        }
        int ans = 1;
        for(int i=1; i<n; i++) {
            if(left[i-1] <= right[i]) ans++;
        }
        return ans;
    }
}