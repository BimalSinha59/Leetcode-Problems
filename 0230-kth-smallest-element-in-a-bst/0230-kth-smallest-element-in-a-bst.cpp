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
    void inOT(TreeNode* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        inOT(root->left,v);
        v.push_back(root->val);
        inOT(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inOrder;
        inOT(root,inOrder);
        return inOrder[k-1];
    }
};