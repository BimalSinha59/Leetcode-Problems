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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int lmin=q.front().second;
            int first,last;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front().first;
                int currIdx=q.front().second-lmin;
                q.pop();
                if(i==0){
                    first=currIdx;
                }
                if(i==size-1){
                    last=currIdx;
                }
                if(node->left!=NULL){
                    q.push({node->left, 2*currIdx+1});
                }
                if(node->right!=NULL){
                    q.push({node->right, 2*currIdx+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
    }
};