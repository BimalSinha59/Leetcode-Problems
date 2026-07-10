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
    ListNode* findMidNode(ListNode* head, ListNode*& prevOfMid) {
        ListNode* slow = head;
        ListNode* fast = head;
        prevOfMid = slow;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                prevOfMid = slow;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* prevOfMid;
        ListNode* midNode = findMidNode(head, prevOfMid);
        prevOfMid->next = NULL;
        ListNode* head2 = reverseLL(midNode);
        ListNode* temp1 = head;
        ListNode* temp2 = head2;
        while (temp1) {
            if (temp1->val != temp2->val) {
                return false;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
};