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
    void reorderList(ListNode* head) {
        ListNode * fast=head->next;
        ListNode * slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * second=slow->next;
        ListNode* pre=nullptr;
        slow->next=nullptr;
        while(second){
            ListNode*nxt=second->next;
            second->next=pre;
            pre=second;
            second=nxt;
        }
        ListNode * first=head;
        second=pre;
        while(second){
            ListNode* tp1=first->next;
            ListNode * tp2=second->next;
            first->next=second;
            second->next=tp1;
            first=tp1;
            second=tp2;
        }
    }
};
