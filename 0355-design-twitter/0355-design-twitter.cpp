class Twitter {
public:
    unordered_map<int,set<pair<int,int>>> user_post;
    unordered_map<int,set<int>>  user_follow;
    int recent=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_post[userId].insert({recent,tweetId});
        recent++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto it: user_post[userId]){
            pq.push(it);
        }
        for(auto it:user_follow[userId]){
            for(auto post:user_post[it]){
                pq.push(post);
            }
        }
        while(!pq.empty()){
            if(ans.size()==10){
                break;
            }
            ans.push_back(pq.top().second);
            pq.pop();

        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follow[followerId].erase(followeeId);
        
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