class Solution {
    public String clearStars(String s) {
        int n = s.length();
        List<List<Integer>>vis = new ArrayList<>();
        for(int i=0; i<26; i++) {
            vis.add(i, new ArrayList<>());
        }
        int[] remove = new int[n];
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == '*') {
                remove[i] = 1;
                for(int j=0; j<26; j++) {
                    if(vis.get(j).size() > 0) {
                        remove[vis.get(j).get(vis.get(j).size() - 1)] = 1;
                        vis.get(j).remove(vis.get(j).size() - 1);
                        break;
                    }
                }
            }
            else {
                vis.get(s.charAt(i) - 'a').add(i);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++) {
            if(remove[i] == 0) sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}