/*
    355. Design Twitter
    Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

    Implement the Twitter class:

    Twitter() Initializes your twitter object.
    void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
    List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
    void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
    void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

    Example 1:

    Input
    ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
    [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    Output
    [null, null, [5], null, null, [6, 5], null, [5]]

    Explanation
    Twitter twitter = new Twitter();
    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    
    Constraints:

    1 <= userId, followerId, followeeId <= 500
    0 <= tweetId <= 104
    All the tweets have unique IDs.
    At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
    A user cannot follow himself
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Twitter {
private:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;       // follower -> set of followees
    unordered_map<int, vector<pair<int, int>>> tweets;      // userId -> list of (timestamp, tweetId)

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // max-heap by timestamp

        // Make sure the user follows themselves
        following[userId].insert(userId);

        // Collect tweets from all followees
        for (int followee : following[userId]) {
            const auto& t = tweets[followee];
            for (int i = max(0, (int)t.size() - 10); i < t.size(); ++i) {
                pq.push(t[i]);
            }
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);                  // User 1 posts tweet 5
    vector<int> feed1 = twitter.getNewsFeed(1); // Should return [5]
    for (int id : feed1) cout << id << " "; cout << endl;

    twitter.follow(1, 2);                     // User 1 follows user 2
    twitter.postTweet(2, 6);                  // User 2 posts tweet 6
    vector<int> feed2 = twitter.getNewsFeed(1); // Should return [6, 5]
    for (int id : feed2) cout << id << " "; cout << endl;

    twitter.unfollow(1, 2);                   // User 1 unfollows user 2
    vector<int> feed3 = twitter.getNewsFeed(1); // Should return [5]
    for (int id : feed3) cout << id << " "; cout << endl;

    return 0;
}
