/*
📝 Design Choice Explanation
Tweet Storage (unordered_map<int, vector<pair<int, int>>> tweets)
- Why? Each user has their own list of tweets, stored as {timestamp, tweetId}.
- Reasoning: Using unordered_map, we can quickly access a user's tweets in O(1) time.
- Pair {timestamp, tweetId} ensures tweets remain sorted by time.

Follower Tracking (unordered_map<int, unordered_set<int>> followers)
- Why? Each user has a set of followees.
- Reasoning: unordered_set allows O(1) insertion/deletion when a user follows/unfollows another.
- Min-Heap (priority_queue<pair<int, int>>, greater<pair<int, int>>)

- Why? We only need the top 10 latest tweets.
- Reasoning: A min-heap efficiently keeps the latest tweets by maintaining the smallest (oldest) tweet at the top.
- We pop the smallest elements if the heap exceeds size 10.


*/

#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int timestamp;  
    unordered_map<int, vector<pair<int, int>>> tweets;  // {userId -> list of {timestamp, tweetId}}
    unordered_map<int, unordered_set<int>> followers;   // {userId -> set of followees}

    Twitter() {
        timestamp = 0;  // Initialize timestamp counter
    }
    
    // O(1) Time Complexity | O(1) Space Complexity
    void postTweet(int userId, int tweetId) {
        // Store the tweet with a global timestamp for chronological order
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    // O(F * T log 10) Time Complexity | O(10) = O(1) Space Complexity
    vector<int> getNewsFeed(int userId) {
        // Min-Heap to store the 10 most recent tweets
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Insert user's own tweets into the heap
        if (tweets.count(userId)) {
            for (auto &t : tweets[userId]) {
                pq.push(t);
                if (pq.size() > 10) pq.pop();  // Keep heap size at most 10
            }
        }

        // Insert followees' tweets into the heap
        if (followers.count(userId)) {
            for (auto &followee : followers[userId]) {
                if (tweets.count(followee)) {
                    for (auto &t : tweets[followee]) {
                        pq.push(t);
                        if (pq.size() > 10) pq.pop();
                    }
                }
            }
        }

        // Extract tweets in correct order
        vector<int> feed;
        while (!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        reverse(feed.begin(), feed.end());  // Latest tweets should come first
        return feed;
    }
    
    // O(1) Time Complexity | O(1) Space Complexity
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId); // Add followee to follower's set
    }
    
    // O(1) Time Complexity | O(1) Space Complexity
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId); // Remove followee from follower's set
    }
};

/*
 * Time Complexity Analysis:
 * - postTweet(): O(1), simply appends to a list.
 * - follow()/unfollow(): O(1), uses unordered_set for fast insert/delete.
 * - getNewsFeed(): O(F * T log 10), iterates over followees' tweets and maintains a heap of size ≤10.
 *
 * Space Complexity Analysis:
 * - Tweets storage: O(U * T) where U = users, T = tweets per user.
 * - Followers storage: O(U * F) where F = followees per user.
 * - Heap for news feed: O(10) = O(1) (always ≤ 10 elements).
 */
