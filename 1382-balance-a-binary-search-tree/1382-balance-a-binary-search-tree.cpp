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
    TreeNode* balanceBST(int low, int high, vector<int>& inorder) {
        if (low > high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = balanceBST(low, mid - 1, inorder);
        root->right = balanceBST(mid + 1, high, inorder);
        return root;
    }
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return balanceBST(0, inorder.size() - 1, inorder);
    }
};