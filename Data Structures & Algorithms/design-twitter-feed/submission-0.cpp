
class Twitter {
public:
    int timestamp = 0;

    // userId -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        // Include the user's own tweets
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Include tweets from followed users
        for (int followeeId : following[userId]) {
            for (auto &tweet : tweets[followeeId]) {
                pq.push(tweet);
            }
        }

        vector<int> feed;

        // Extract the 10 most recent tweets
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
