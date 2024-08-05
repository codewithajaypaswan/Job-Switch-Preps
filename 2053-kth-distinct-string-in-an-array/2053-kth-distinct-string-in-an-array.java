class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer>mp = new HashMap<>();
        for(String s:arr) {
            mp.put(s, mp.getOrDefault(s, 0) + 1);
        }
        for(String s:arr) {
            if(mp.get(s) == 1) k--;
            if(k == 0) return s;
        }
        return new String();
    }
}