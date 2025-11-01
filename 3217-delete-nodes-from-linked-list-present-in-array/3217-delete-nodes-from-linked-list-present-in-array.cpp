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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* temp = head;
        while (temp) {
            mp[temp->val]++;
            temp = temp->next;
        }
        for (int& ele : nums) {
            if (mp.count(ele)) {
                mp.erase(ele);
            }
        }
        ListNode* ans;
        temp = head;
        while (temp) {
            if (mp[temp->val]) {
                ans = new ListNode(temp->val);
                break;
            }
            temp = temp->next;
        }
        temp = temp->next;
        ListNode* res = ans;
        while (temp) {
            if (mp[temp->val]) {
                ListNode* node = new ListNode(temp->val);
                ans->next = node;
                ans = ans->next;
            }
            temp = temp->next;
        }
        return res;
    }
};