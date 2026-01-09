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
    int maxi = -1;
    unordered_map<int, int> mp;
    TreeNode* lowestCommonAncestor(TreeNode* root) {
        if (root == NULL || mp[root->val] == maxi) {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left);
        TreeNode* r = lowestCommonAncestor(root->right);
        if (l && r) {
            return root;
        }
        return l ? l : r;
    }
    void computeDN(TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }
        maxi = max(maxi, depth);
        mp[root->val] = depth;
        computeDN(root->left, depth + 1);
        computeDN(root->right, depth + 1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        computeDN(root, 0);
        return lowestCommonAncestor(root);
    }
};