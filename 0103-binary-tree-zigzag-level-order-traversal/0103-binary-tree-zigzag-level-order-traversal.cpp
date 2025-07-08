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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        int c=1;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node!=NULL) temp.push_back(node->val);
            q.pop();
            if(node==NULL){
                if(c&1){
                    ans.push_back(temp);
                }
                else{
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
                if(!q.empty()){
                    q.push(NULL);
                    c++;
                    temp.clear();
                }
            }
            else{
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};