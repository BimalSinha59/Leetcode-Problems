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
    TreeNode* constructTree(int& preOrderIdx, int inorderStart, int inorderEnd,
                            int& n, vector<int>& preorder, vector<int>& inorder,
                            unordered_map<int, int>& eleToIdxMap) {
        if (preOrderIdx >= n) {
            return NULL;
        }
        if (inorderStart > inorderEnd) {
            return NULL;
        }
        int nodeElement = preorder[preOrderIdx];
        preOrderIdx++;
        TreeNode* node = new TreeNode(nodeElement);
        int eleIdxInInoder = eleToIdxMap[nodeElement];
        node->left = constructTree(preOrderIdx, inorderStart, eleIdxInInoder - 1, n,
                                    preorder, inorder, eleToIdxMap);
        node->right = constructTree(preOrderIdx, eleIdxInInoder + 1, inorderEnd,
                                    n, preorder, inorder, eleToIdxMap);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int inorderStart = 0, inorderEnd = n - 1;
        int preOrderIdx = 0;
        unordered_map<int, int> eleToIdxMap;
        for (int i = 0; i < n; i++) {
            eleToIdxMap[inorder[i]] = i;
        }
        TreeNode* root = constructTree(preOrderIdx, inorderStart, inorderEnd, n,
                                    preorder, inorder, eleToIdxMap);
        return root;
    }
};