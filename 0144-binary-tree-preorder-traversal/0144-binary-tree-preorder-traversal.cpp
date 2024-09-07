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
    vector<int>pre;
    
    void preorder(TreeNode* root){
        pre.push_back(root->val);
        
        if(root->left)preorderTraversal(root->left);
        if(root->right)preorderTraversal(root->right);
        
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root!=NULL)
        preorder(root);
        return pre;
    }
};