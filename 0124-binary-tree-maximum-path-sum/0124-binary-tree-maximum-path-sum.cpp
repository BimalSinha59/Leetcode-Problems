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
    int findMax(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }
        int leftAns=max(0,findMax(root->left, maxi));
        int rightAns=max(0,findMax(root->right, maxi));
        maxi=max(maxi, leftAns + rightAns + root->val);
        return max(leftAns,rightAns) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        findMax(root, maxi);
        return maxi;
    }
};