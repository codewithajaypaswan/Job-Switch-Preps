class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        Map<Integer, Integer>mp = new TreeMap<>();
        for(int x:hand) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for(Map.Entry<Integer, Integer>entry: mp.entrySet()) {
            int val = entry.getKey();
            int freq = entry.getValue();
            if(freq > 0) {
                for(int i=0; i<groupSize; i++) {
                    if(mp.getOrDefault(val + i, 0) < freq) return false;
                    mp.put(val+i, mp.get(val + i) - freq);
                    
                }
            }
        }
        return true;
    }
}