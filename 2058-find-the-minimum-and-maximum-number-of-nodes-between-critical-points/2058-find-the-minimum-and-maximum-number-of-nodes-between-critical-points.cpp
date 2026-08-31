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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = 1e9;
        int maxi = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int last_cp = -1;
        int first_cp = -1;
        int cnt = 0;
        while (temp) {
            if (temp->next) {
                forward = temp->next;
            } else {
                forward = NULL;
            }
            if (prev && forward &&
                ((prev->val < temp->val && temp->val > forward->val) ||
                 (prev->val > temp->val && temp->val < forward->val))) {
                if (last_cp != -1) {
                    mini = min(mini, cnt - last_cp);
                    if (first_cp != -1) {
                        maxi = max(maxi, cnt - first_cp);
                    }
                }
                if (first_cp == -1) {
                    first_cp = cnt;
                }
                last_cp = cnt;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (mini == 1e9 || maxi == 0) {
            return {-1, -1};
        }
        return {mini, maxi};
    }
};