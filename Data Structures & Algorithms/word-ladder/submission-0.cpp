class Solution {
    private:
    bool canConversion(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;

    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) {
                return level;
            }

            vector<string> toDelete;

            for (const string& item : wordSet) {
                if (canConversion(word, item)) {
                    q.push({item, level + 1});
                    toDelete.push_back(item);
                }
            }

            // 删除已经访问的单词
            for (const string& s : toDelete) {
                wordSet.erase(s);
            }
        }

        return 0;
    }
};