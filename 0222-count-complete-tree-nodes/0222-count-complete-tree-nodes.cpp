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
    int findLH(TreeNode* node){
        int lh=0;
        while(node){
            node=node->left;
            lh++;
        }
        return lh;
    }
    int findRH(TreeNode* node){
        int rh=0;
        while(node){
            node=node->right;
            rh++;
        }
        return rh;
    }

    int findNodes(TreeNode* root){
        int lh=findLH(root);
        int rh=findRH(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+findNodes(root->left)+findNodes(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return findNodes(root);
    }
};