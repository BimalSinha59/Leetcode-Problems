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
    int getLength(ListNode* curr) {
        int ans = 0;
        while (curr) {
            curr = curr->next;
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
        k = n - k;
        ListNode* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
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