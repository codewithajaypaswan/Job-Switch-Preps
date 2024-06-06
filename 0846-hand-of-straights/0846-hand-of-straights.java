class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        Map<Integer, Integer>mp = new TreeMap<>();
        for(int x:hand) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for(int val:mp.keySet()) {
            int freq = mp.get(val);
            if(freq > 0) {
                for(int i=0; i<groupSize; i++) {
                    if(!mp.containsKey(val + i)) return false;
                    int nextVal = mp.get(val + i);
                    if(nextVal - freq < 0) return false;
                    mp.put(val + i, nextVal - freq);
                }
            }
        }
        return true;
    }
}