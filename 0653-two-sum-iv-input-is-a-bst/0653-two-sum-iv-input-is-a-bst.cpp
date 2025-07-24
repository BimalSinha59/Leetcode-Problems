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
    void inO(TreeNode* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        inO(root->left,v);
        v.push_back(root->val);
        inO(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        vector<int>v;
        inO(root,v);
        int i=0,j=v.size()-1;
        if(v.size()==1) return false;
        bool ans=false;
        while(i<j){
            if(v[i]+v[j]==k){
                ans=true;
                break;
            }
            else if(v[i]+v[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};