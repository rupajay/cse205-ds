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
    void help(vector<vector<int>>& ans, vector<int>& temp, TreeNode* root,vector<int>&w) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int x = q.size();

            for (int i = 0; i < x; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // ans.push_back(temp); 
            int e=temp.back();
            w.push_back(e);
            temp.clear(); 
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int>w;
        help(ans,temp,root,w);
        return w;
    }
};