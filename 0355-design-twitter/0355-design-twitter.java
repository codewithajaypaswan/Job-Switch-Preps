class Twitter {
    private Map<Integer, Set<Integer>>fo;
    private Map<Integer, List<int[]>>tw;
    private int timer;
    public Twitter() {
        fo = new HashMap<>();
        tw = new HashMap<>();
        timer = 0;
    }
    
    public void postTweet(int userId, int tweetId) {
        tw.putIfAbsent(userId, new ArrayList<>());
        tw.get(userId).add(new int[] {timer++, tweetId});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> ans = new ArrayList<>();
        PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt((int[] a) -> a[0]).reversed());
        if(tw.containsKey(userId)) {
            for(int[] t:tw.get(userId)) {
                pq.offer(t);
            }
        }
        if(fo.containsKey(userId)) {
            for(int user:fo.get(userId)) {
                if(tw.containsKey(user)) {
                    for(int[] t:tw.get(user)) {
                        pq.offer(t);
                    }
                }
            }
        }
        while(!pq.isEmpty()) {
            int[] t = pq.poll();
            ans.add(t[1]);
            if(ans.size() == 10) return ans;
        }
        return ans;
    }
    
    public void follow(int followerId, int followeeId) {
        fo.putIfAbsent(followerId, new HashSet<>());
        fo.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        fo.putIfAbsent(followerId, new HashSet<>());
        fo.get(followerId).remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */