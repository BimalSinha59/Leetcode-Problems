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
    const int mod = 1e9 + 7;
    void totalSum(TreeNode* root, int& tsum) {
        if (root == NULL) {
            return;
        }
        totalSum(root->left, tsum);
        totalSum(root->right, tsum);
        tsum += root->val;
    }
    int nodeSum(TreeNode* root, long long& ans, int tsum) {
        if (root == NULL) {
            return 0;
        }
        int sum = root->val + nodeSum(root->left, ans, tsum) + nodeSum(root->right, ans, tsum);
        int remSum = tsum - sum;
        long long pdt = 1LL * sum * remSum;
        ans = max(ans, pdt);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int tsum = 0;
        totalSum(root, tsum);
        long long ans = 0;
        nodeSum(root, ans, tsum);
        int res = ans % mod;
        return res;
    }
};