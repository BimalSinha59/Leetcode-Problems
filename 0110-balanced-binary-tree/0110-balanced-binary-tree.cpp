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
    int getH(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(getH(root->left), getH(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int lh = getH(root->left);
        int rh = getH(root->right);
        int Diff = abs(lh - rh);
        bool ans = (Diff <= 1);

        bool lAns = isBalanced(root->left);
        bool rAns = isBalanced(root->right);

        return ans && lAns && rAns;
    }
};