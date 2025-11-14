// Design Twitter

// Link: https://leetcode.com/problems/design-twitter/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Twitter {
private:
    // user -> set of users they follow
    unordered_map<int, unordered_set<int>> followList;
    // user -> list of (time, tweetId) appended on post
    unordered_map<int, vector<pair<int,int>>> userTweets;
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        followList[userId].insert(userId);
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followList[userId].insert(userId);

        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        // push latest tweet from each followed user
        for (int uid : followList[userId]) {
            auto &vec = userTweets[uid];
            if (!vec.empty()) {
                int idx = (int)vec.size() - 1;
                pq.emplace(vec[idx].first, vec[idx].second, uid, idx);
            }
        }

        // collect up to 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {
            auto [time, tweetId, uid, idx] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
            if (idx - 1 >= 0) {
                auto &vec = userTweets[uid];
                pq.emplace(vec[idx-1].first, vec[idx-1].second, uid, idx-1);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        // followerId follows followeeId
        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // per common spec, don't allow unfollowing yourself
        if (followerId == followeeId) return;
        auto it = followList.find(followerId);
        if (it != followList.end()) {
            it->second.erase(followeeId);
        }
    }
};