class Solution {
    public int longestWPI(int[] hours) {
        HashMap<Integer, Integer>mp = new HashMap<>();
        int ans = 0;
        for(int i=0, cnt = 0; i<hours.length; i++) {
            cnt += hours[i] > 8 ? 1 : -1;
            if(cnt > 0) ans = i+1;
            else if(mp.containsKey(cnt - 1)) {
                ans = Math.max(ans, i - mp.get(cnt - 1));
            }
            else if(!mp.containsKey(cnt)) {
                mp.put(cnt, i);
            }
        }
        return ans;
    }
}