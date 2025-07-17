/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                ans += '#';
            } else {
                ans += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        TreeNode* root = new TreeNode((data[0] - '0'));
        int j = 1;
        int n = data.size();
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (j < n && data[j] == '#') {
                node->left = NULL;
            }
            else {
                if (j < n){
                    node->left = new TreeNode(data[j]-'0');
                    q.push(node->left);
                }
            }
            if (j + 1 < n && data[j + 1] == '#') {
                node->right = NULL;
            } 
            else {
                if (j + 1 < n){
                    node->right = new TreeNode(data[j + 1] - '0');
                    q.push(node->right);
                }
            }
            j = j + 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));