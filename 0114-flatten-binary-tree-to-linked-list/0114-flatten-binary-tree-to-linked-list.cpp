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
    TreeNode *pre=NULL;
    void flatten(TreeNode* root) {
        TreeNode *node =root;
        
            if(node==NULL)return;
            flatten(node->right);
            flatten(node->left);

            node->right=pre;
            node->left=NULL;
            pre=node;
        
    }
};