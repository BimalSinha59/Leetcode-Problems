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
    void inOT(TreeNode* root,int &cnt, int k, int &ans){
        if(root==NULL){
            return;
        }
        inOT(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        inOT(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>inOrder;
        // inOT(root,inOrder);
        // return inOrder[k-1];
        int cnt=0;
        int ans=0;
        inOT(root,cnt,k,ans);
        return ans;
    }
};