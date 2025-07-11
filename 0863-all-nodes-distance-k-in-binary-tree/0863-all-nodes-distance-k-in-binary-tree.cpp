/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void linkChildToParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_link){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent_link[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_link[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<TreeNode*,TreeNode*>parent_link;
        linkChildToParent(root,parent_link);

        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level==k){
                break;
            }
            curr_level++;
            for(int i=0; i<size; i++){
                TreeNode* currNode=q.front();
                q.pop();
                if(currNode->left && !vis[currNode->left]){
                    q.push(currNode->left);
                    vis[currNode->left]=true;
                }
                if(currNode->right && !vis[currNode->right]){
                    q.push(currNode->right);
                    vis[currNode->right]=true;
                }
                if(parent_link[currNode] && !vis[parent_link[currNode]]){
                    q.push(parent_link[currNode]);
                    vis[parent_link[currNode]]=true;
                }
            }

        }

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};