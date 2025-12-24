/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, int> mp1;
        int idx = 0;
        while (temp) {
            mp1[temp] = idx;
            temp = temp->next;
            idx++;
        }
        unordered_map<int, Node*> mp2;
        temp = head;
        idx = 0;
        while (temp) {
            Node* nnode = new Node(temp->val);
            mp2[idx] = nnode;
            temp = temp->next;
            idx++;
        }
        for (auto& it : mp1) {
            Node* node = it.first;
            int idx = it.second;
            int nidx = -1;
            if (node->next) {
                nidx = mp1[node->next];
            }
            int ridx = -1;
            if (node->random) {
                ridx = mp1[node->random];
            }
            Node* nnode = mp2[idx];
            if (nidx == -1) {
                nnode->next = NULL;
            } else {
                nnode->next = mp2[nidx];
            }
            if (ridx == -1) {
                nnode->random = NULL;
            } else {
                nnode->random = mp2[ridx];
            }
        }
        return mp2[0];
    }
};