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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<ll,ll>m;
        for(ll i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode* constructTree(vector<ll>&preorder,ll prestart,ll preend,vector<ll>&inorder,ll instart,ll inend,map<ll,ll>&m){
        //base condition
        if(prestart>preend || instart>inend)return NULL;

        // make a new node
        TreeNode *root=new TreeNode(preorder[prestart]);
        ll inroot=m[root->val];
        ll numleft=inroot-instart;
        root->left=constructTree(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,m);
        root->right=constructTree(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,m);

        return root;
    }
};