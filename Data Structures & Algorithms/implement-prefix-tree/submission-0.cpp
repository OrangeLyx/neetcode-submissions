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
class PrefixTree {
    private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
         Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true; // 标记单词结束
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return cur->isEnd; // 必须刚好到达单词末尾
    }
    
    bool startsWith(string prefix) {
         Node* cur = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return true; // 只要能走
    }
};
