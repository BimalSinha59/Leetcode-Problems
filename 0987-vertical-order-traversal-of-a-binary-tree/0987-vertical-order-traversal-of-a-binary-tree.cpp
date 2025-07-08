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
    void preOT(TreeNode* root, map<pair<int,int>,vector<int>>& mp, int c, int r, int &mini, int &maxi){
        if(root==NULL){
            return;
        }
        mini=min(mini,c);
        maxi=max(maxi,c);
        mp[{c,r}].push_back(root->val);
        preOT(root->left, mp, c-1, r+1, mini, maxi);
        preOT(root->right, mp, c+1, r+1, mini, maxi);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int r=0,c=0;
        int mini=1e9, maxi=-1e9;
        map<pair<int,int>,vector<int>>mp;
        preOT(root, mp, r,c, mini,maxi);
        vector<vector<int>>ans(abs(mini)+maxi+1);
        for(auto it:mp){
            // cout<<it.first.first<<" "<<it.first.second<<" : ";
            // for(auto i:it.second){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            int c=it.first.first+abs(mini);
            auto v=it.second;
            if(v.size()>1){
                sort(v.begin(), v.end());
            }
            for(auto i:v){
                ans[c].push_back(i);
            }

        }
        return ans;
    }
};