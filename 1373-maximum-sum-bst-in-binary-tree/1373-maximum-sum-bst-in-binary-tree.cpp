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

class NodeValue {
public:
    int minValue, maxValue, maxSum;
    NodeValue(int minValue, int maxValue, int maxSum) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSum = maxSum;
    }
};

class Solution {
public:
    NodeValue maxSumBSTHelper(TreeNode* root, int& ans) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = maxSumBSTHelper(root->left, ans);
        auto right = maxSumBSTHelper(root->right, ans);
        if (left.maxValue < root->val && root->val < right.minValue) {
            int currSum = left.maxSum + right.maxSum + root->val;
            ans = max(ans, currSum);
            return NodeValue(min(left.minValue, root->val),
                             max(right.maxValue, root->val), currSum);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        maxSumBSTHelper(root, ans);
        return ans;
    }
};