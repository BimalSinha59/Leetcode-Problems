/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> flg;
        for (auto& node : descriptions) {
            int parent = node[0];
            int child = node[1];
            flg[child] = true;
            int isLeft = node[2];
            TreeNode* curr;
            if (mp.find(parent) == mp.end()) {
                curr = new TreeNode(parent);
                mp[parent] = curr;
            } else {
                curr = mp[parent];
            }
            TreeNode* child_node;
            if (mp.find(child) == mp.end()) {
                child_node = new TreeNode(child);
                mp[child] = child_node;
            } else {
                child_node = mp[child];
            }
            if (isLeft) {
                curr->left = child_node;
            } else {
                curr->right = child_node;
            }
        }
        TreeNode* root;
        for (auto& node : descriptions) {
            if (flg.find(node[0]) == flg.end()) {
                root = mp[node[0]];
                break;
            }
        }
        return root;
    }
};