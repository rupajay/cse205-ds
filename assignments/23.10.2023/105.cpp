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
    unordered_map<int, int> mp;
    int idx = 0; // Preorder index

    TreeNode* help(vector<int>& pre, vector<int>& in, int start, int end) {

        if (start > end) {
            return nullptr;
        }

        int val = pre[idx];
        TreeNode* root = new TreeNode(val);
        idx++;

        int pos = mp[val]; // Index of val in inorder

        root->left = help(pre, in, start, pos - 1);
        root->right = help(pre, in, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return help(preorder, inorder, 0, inorder.size() - 1);
    }
};