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

    vector<int> vec;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);

        int left = 0;
        int right = vec.size() - 1;

        while(left < right){
            if(vec[left] + vec[right] == k){
                return true;
            }
            else if(vec[left] + vec[right] < k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};