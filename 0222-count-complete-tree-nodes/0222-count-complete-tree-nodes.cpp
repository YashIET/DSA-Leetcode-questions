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
    typedef int ll;
    void dfs(TreeNode* root,ll &cnt){
        if(root==NULL)return ;
        cnt++;
        if(root->left)dfs(root->left,cnt);
        if(root->right)dfs(root->right,cnt);
        return ;
    }
    int countNodes(TreeNode* root) {
        ll cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};