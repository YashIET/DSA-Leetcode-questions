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
    void rec(TreeNode* node, vector<int>&ans,int level){
        if(node==NULL)return ;
        if(ans.size()==level)ans.push_back(node->val);
        //call right then left for right view
        rec(node->right,ans,level+1);
        rec(node->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        TreeNode* temp=root;
        rec(root,ans,0);
        //level is given and push only when vector size equals to current level;
        return ans;
    }
};