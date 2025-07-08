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
    void preot(TreeNode* root,queue<TreeNode*>& q){
        if(root == NULL){
            return;
        }
        q.push(root);
        preot(root->left, q);
        preot(root->right, q);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        preot(root, q);
        if(!q.empty()){
            q.pop();
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
           
            root->right=node;
            root->left=NULL;
            root=root->right;
            
        }
    }
};