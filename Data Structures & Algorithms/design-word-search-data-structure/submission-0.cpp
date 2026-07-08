struct Node {
    bool isEnd;
    Node* children[26];

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(string& word, int idx, Node* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isEnd;

        char c = word[idx];
        if (c == '.') {
            // '.' => 尝试所有分支
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int k = c - 'a';
            return dfs(word, idx + 1, node->children[k]);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new Node();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
