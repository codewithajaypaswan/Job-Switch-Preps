class Solution {
    public long dividePlayers(int[] skill) {
        long ans = 0, sum = 0;
        for(int x:skill) {
            sum += x;
        }
        long equal;
        equal = sum / (long)(skill.length/2);
        if(sum%equal != 0) return -1;
        int k = (int)equal; 
        Map<Integer, Integer>mp = new HashMap<>();
        for(int x:skill) {
            if(mp.containsKey(k - x) && mp.get(k-x) > 0) {
                mp.put(k-x, mp.get(k-x) - 1);
                ans += (long)x*(k-x);
            }
            else {
                mp.put(x, mp.getOrDefault(x, 0) + 1);
            }
        }
        for(Map.Entry<Integer, Integer> entry: mp.entrySet()) {
            if(entry.getValue() > 0) return -1;
        }
        return ans;
    }
}