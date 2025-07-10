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
    void preOT(TreeNode* root, string &s, vector<string>& ans){
        if(root==NULL){
            return;
        }
        int size=s.size();
        if(size!=0){
            s+="->";
        }
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            s.erase(size);
            return;
        }
        preOT(root->left,s,ans);
        preOT(root->right,s,ans);
        s.erase(size);
        return;
    }

    void f(TreeNode* root, string s, vector<string>& ans){
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
        }
        if(root->left!=NULL){
            f(root->left,s+"->",ans);
        }
        if(root->right!=NULL){
            f(root->right,s+"->",ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL){
            return ans;
        }
        string s="";
        //preOT(root,s,ans);
        f(root,s,ans);
        return ans;
    }
};