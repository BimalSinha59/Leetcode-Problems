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
    ListNode* revLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* curr_prev = NULL;
        ListNode* curr_next = NULL;
        while (curr) {
            curr_next = curr->next;
            curr->next = curr_prev;
            curr_prev = curr;
            curr = curr_next;
        }
        return curr_prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        int max_twin_sum = 0;
        ListNode* lptr = head;
        ListNode* rptr = revLL(slow);
        while (rptr) {
            int sum = lptr->val + rptr->val;
            max_twin_sum = max(max_twin_sum, sum);
            lptr = lptr->next;
            rptr = rptr->next;
        }
        return max_twin_sum;
    }
};