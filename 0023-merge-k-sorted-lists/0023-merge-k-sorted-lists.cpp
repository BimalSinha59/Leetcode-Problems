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
    void insert(ListNode** ans, int item) {
        ListNode* temp = new ListNode(item);
        temp->next = *ans;
        *ans = temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        vector<int> v;
        for (auto it : lists) {
            ListNode* temp = it;
            while (temp != NULL) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* ans = NULL;
        int n = v.size();
        for (int i = n - 1; i >= 0; i--) {
            insert(&ans, v[i]);
        }
        return ans;
    }
};