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
    bool isValidBST(TreeNode* root) {
        return findBST(root, LONG_MIN, LONG_MAX);
    }

    bool findBST(TreeNode* root, long int min, long int max){
        if(root == NULL){
            return true;
        }
        if(root->val <= min || root->val >= max){
            return false;
        }

        return (findBST(root->left, min, root->val) && findBST(root->right, root->val, max));
    }
};