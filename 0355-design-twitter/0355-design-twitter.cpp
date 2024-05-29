class Twitter {
public:
    unordered_map<int, set<int>>fo;
    unordered_map<int, vector<pair<int,int>>>tw; // userId, timer, tweetId
    int timer = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tw[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;
        for(auto t:tw[userId]) {
            pq.push(t);
        }
        
        for(auto user:fo[userId]) {
            for(auto t:tw[user]) {
                pq.push(t);
            }
        }
        
        vector<int>ans;
        while(!pq.empty()) {
            auto tweet = pq.top().second; pq.pop();
            ans.push_back(tweet);
            if(ans.size() == 10) return ans;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */