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
    int findLeftHeight(TreeNode* root) {
        int height = 0;
        TreeNode* temp = root;
        while (temp) {
            height++;
            temp = temp->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* root) {
        int height = 0;
        TreeNode* temp = root;
        while (temp) {
            height++;
            temp = temp->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};