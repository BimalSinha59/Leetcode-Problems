class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) {
                pq.pop();
            }
        }
        for (auto& followee : following[userId]) {
            for (auto& tweet : tweets[followee]) {
                pq.push(tweet);
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            int post = pq.top().second;
            pq.pop();
            res.push_back(post);
            if (res.size() == 10) {
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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