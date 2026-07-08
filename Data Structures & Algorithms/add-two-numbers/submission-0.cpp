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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        int carry = 0;
        int n1 = 0, n2 = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1) {
                n1 = l1->val;
            } else {
                n1 = 0;
            }
            if (l2) {
                n2 = l2->val;
            } else {
                n2 = 0;
            }
            int sum = n1 + n2 + carry;
            pre->next = new ListNode(sum % 10);
            carry = sum / 10;
            pre = pre->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            pre->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
