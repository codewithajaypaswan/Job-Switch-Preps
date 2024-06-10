class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] temp = Arrays.copyOf(heights, heights.length);
        Arrays.sort(temp);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(temp[i] != heights[i]) ans++;
        }
        return ans;
    }
}