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
    void help(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL)return;
            queue<TreeNode* >q;
            bool rev=false;

            q.push(root);
            while(!q.empty()){
                int x=q.size();
                for(int i=0;i<x;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                }
                if(rev)reverse(begin(temp),end(temp));
                rev=!rev;

                ans.push_back(temp); 
                temp.clear(); 
            }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int>temp;
        vector<vector<int>>ans;
        help(root,temp,ans);
        return ans;
    }
};