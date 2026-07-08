/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto& head:lists){
            if (head) {
                q.push(head);
            }
        }
        ListNode * dummy=new ListNode(0);
        ListNode * cur=dummy;
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            if(node->next){
                q.push(node->next);
            }
            cur->next=node;
            cur=cur->next;
        }
        return dummy->next;
    }
};
