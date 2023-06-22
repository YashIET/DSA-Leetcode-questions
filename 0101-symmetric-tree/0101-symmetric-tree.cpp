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
    bool check(TreeNode* lefti,TreeNode* righti){
        if(lefti==NULL || righti==NULL)return lefti==righti;

        return (lefti->val==righti->val  && check(lefti->left,righti->right) && check(lefti->right,righti->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return check(root->left,root->right);
    }
};