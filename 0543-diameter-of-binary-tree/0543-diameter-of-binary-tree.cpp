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
    int diameterOfBinaryTree(TreeNode* root) {
       ll diameter=0;
       height(root,diameter);
       return diameter;
    }
    ll height(TreeNode* root,ll &diameter){

        if(!root)return 0;
        ll lh=height(root->left,diameter);
        ll rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+(max(lh,rh));
    }
};