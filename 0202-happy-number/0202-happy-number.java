class Solution {
    public boolean isHappy(int n) {
        HashMap<Integer, Integer>mp = new HashMap<>();
        while(n != 1) {
            if(mp.containsKey(n)) return false;
            mp.put(n, 1);
            n = next(n);
        }
        return true;
    }
    
    int next(int n) {
        int ans = 0;
        while(n > 0) {
            int rem = n%10;
            ans += rem*rem;
            n = n/10;
        }
        return ans;
    }
}