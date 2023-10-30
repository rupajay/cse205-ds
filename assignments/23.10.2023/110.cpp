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
        int help(TreeNode* root){
            if(root == NULL){
                return 0;
            }
            int l = help(root->left);
            int r = help(root->right);
            if(r == -1 || l == -1){
                return -1;
            }
            if(abs(r-l) > 1){
                return -1;
            }
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root){
        if(help(root) != -1){
            return true;
        }
        else{
            return false;
        }
    }
};