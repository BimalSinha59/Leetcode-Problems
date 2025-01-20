/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root,long long l, long long r){
        if(root==NULL){
            return true;
        }
        if(root->val>=r || root->val<=l){
            return false;
        }

        return solve(root->left,l,root->val) && solve(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-1e18,1e18);
    }
};