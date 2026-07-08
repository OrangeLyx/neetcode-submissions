
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k = 0, int v = 0) : key(k), value(v) {};
};
class LRUCache {
private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void push_front(Node* x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }
    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }
        Node* node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        Node* node = get_node(key);
        if (node) {
            node->value = value;
            return;
        }

        node = new Node(key, value); 
        key_to_node[key] = node;
        push_front(node);
        if (capacity < key_to_node.size()) {
            Node* drop = dummy->prev;
            key_to_node.erase(drop->key);
            remove(drop);
            delete drop;
        }
    }
};
