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
    TreeNode* ctpLink(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp, int start){
        TreeNode* target;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node->val==start){
                target=node;
            }
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* target=ctpLink(root, mp, start);
        int ans=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]]=true;
                }
            }
        }
        return ans-1;
    }
};