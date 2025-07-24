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
    
    void recoverTree(TreeNode* root) {
        TreeNode* aa=NULL;
        TreeNode* bb=NULL;
        TreeNode* prev=NULL;
        TreeNode* rmst=NULL;
        while(root){
            if(root->left){
                rmst=root->left;
                while(rmst->right && rmst->right!=root){
                    rmst=rmst->right;
                }
                if(!rmst->right){
                    rmst->right=root;
                    root=root->left;
                }
                else{
                    if(prev && prev->val>root->val){
                        if(!aa){
                            aa=prev;
                        }
                        bb=root;
                    }
                    rmst->right=NULL;
                    prev=root;
                    root=root->right;
                }
            }
            else{
                if(prev && prev->val>root->val){
                    if(!aa){
                        aa=prev;
                    }
                    bb=root;
                }
                prev=root;
                root=root->right;
            }
        }
        if(aa && bb){
            swap(aa->val,bb->val);
        }
    }
};