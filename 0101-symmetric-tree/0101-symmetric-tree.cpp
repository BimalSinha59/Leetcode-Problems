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
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL){
            return root;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    bool isSame(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        if(p->val==q->val){
            return isSame(p->left,q->left) && isSame(p->right,q->right);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
       if(root==NULL){
        return true;
       }
       TreeNode* p=root->right;
       TreeNode* q=invertTree(root->left);
       return isSame(p,q);       
    }
};