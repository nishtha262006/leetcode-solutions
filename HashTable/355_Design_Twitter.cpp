// LeetCode 355 - Design Twitter

// Difficulty: Medium

// Approach:

// 1. Design a `Twitter` class to support posting tweets, following/unfollowing users, and retrieving the news feed.
// 2. Store each user's tweets along with a timestamp so newer tweets can be identified.
// 3. Maintain a mapping of each user to the set of users they follow.
// 4. When a user posts a tweet:

//    * Assign an increasing timestamp.
//    * Store the tweet for that user.
// 5. When generating the news feed:

//    * Collect tweets from the user and everyone they follow.
//    * Use a Max Heap (Priority Queue) to retrieve tweets in descending order of timestamp.
//    * Return the 10 most recent tweet IDs.
// 6. For follow/unfollow operations:

//    * Update the follower's follow set.
//    * Ignore invalid unfollow operations such as unfollowing oneself if required by the implementation.

// Time Complexity:

// * `postTweet`: **O(1)**
// * `follow`: **O(1)**
// * `unfollow`: **O(1)**
// * `getNewsFeed`: **O((T + F) log(T + F))** (heap-based approach)

// Space Complexity: O(T + F)

// * T = total number of stored tweets.
// * F = total follow relationships.



class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> followMap;

    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        for(auto &tweet : tweets[userId])
            pq.push(tweet);

        for(int followee : followMap[userId]) {

            for(auto &tweet : tweets[followee])
                pq.push(tweet);
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if(followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        followMap[followerId].erase(followeeId);
    }
};