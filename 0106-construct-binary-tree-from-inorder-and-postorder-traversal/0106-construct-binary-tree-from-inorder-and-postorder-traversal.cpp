/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* makeTree(int iostart, int ioend, int& pidx, vector<int>& inorder,
                       vector<int>& postorder, unordered_map<int, int>& mp) {

        if (pidx < 0) {
            return NULL;
        }
        if (iostart > ioend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pidx]);
        int ioidx = mp[postorder[pidx]];
        pidx--;
        root->right = makeTree(ioidx + 1, ioend, pidx, inorder, postorder, mp);
        root->left = makeTree(iostart, ioidx - 1, pidx, inorder, postorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        int pidx = n - 1;
        return makeTree(0, n - 1, pidx, inorder, postorder, mp);
    }
};