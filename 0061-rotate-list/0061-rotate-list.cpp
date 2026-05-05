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
    int getLength(ListNode* head) {
        int ans = 0;
        while (head) {
            head = head->next;
            ans++;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int n = getLength(head);
        k = k % n;
        if (k == 0) {
            return head;
        }
        k = n - k - 1;
        ListNode* temp = head;
        while (k) {
            temp = temp->next;
            k--;
        }
        ListNode* lNode = temp;
        while (lNode->next) {
            lNode = lNode->next;
        }
        lNode->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};