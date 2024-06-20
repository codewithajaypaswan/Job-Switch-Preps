class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n = position.length, ans = 0;
        int low = 0, high = position[n-1];
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(position, mid, m)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
    
    boolean check(int[] position, int mid, int m) {
        int cnt = 1, cur = position[0];
        for(int i=1; i<position.length; i++) {
            if(position[i] - cur >= mid) {
                cnt++;
                cur = position[i];
            }
        }
        return cnt >= m;
    }
}