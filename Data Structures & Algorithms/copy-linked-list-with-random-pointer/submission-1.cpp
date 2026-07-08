/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* cur = head; cur; cur = cur->next->next) {
            // cur->next = new Node(cur->val, cur->next, nullptr);
             Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }

        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        Node* new_head = head->next;
        Node* cur = head;
        for (; cur->next->next; cur = cur->next) {
            Node* copy = cur->next;
            cur->next = cur->next->next;
            copy->next = copy->next->next;
        }
        cur->next = nullptr;
        return new_head;
    }
};
