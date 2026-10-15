/**
 * Definition for a binary tree root.
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
    int findHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        int currentDiameter = leftHeight + rightHeight;

        int leftDiameter = diameterOfBinaryTree(root->left);

        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};