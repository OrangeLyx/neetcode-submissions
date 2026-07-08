class Twitter {
    unordered_map<int, set<int>> followMap;
    int time;
    unordered_map<int, vector<vector<int>>> tweetMap;

public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);

        followMap[userId].insert(userId);
        // 取 feed 时，把‘关注的人’的多条有序列表做 K 路归并
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                // followee 目前放进堆里的那条 tweet，在他自己的 tweetMap[followeeId] 里的位置
                maxHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

         while (!maxHeap.empty() && res.size() < 10) {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                maxHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
