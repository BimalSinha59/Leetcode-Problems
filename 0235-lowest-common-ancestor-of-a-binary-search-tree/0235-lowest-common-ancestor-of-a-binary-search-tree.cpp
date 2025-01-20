/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val;
        int qv = q->val;
        int rv = root->val;
        if (root == NULL) {
            return NULL;
        }

        if(pv<rv && qv<rv){
            return lowestCommonAncestor(root->left,p,q);
        }

        if(pv>rv && qv>rv){
            return lowestCommonAncestor(root->right,p,q);
        }

        return root;
    }
};