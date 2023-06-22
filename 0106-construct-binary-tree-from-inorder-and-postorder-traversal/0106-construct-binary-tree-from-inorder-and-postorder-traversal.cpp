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
public:typedef int ll;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<ll,ll>m;
        for(ll i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=construct(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
        return root;
    }
    //note that we assume postend as last no in postorder array:)
    TreeNode* construct(vector<ll>&inorder,ll instart,ll inend,vector<ll>&postorder,ll poststart,ll postend,map<ll,ll>&m){
        //base condn
        if(poststart>postend || instart>inend)return NULL;
        
        //make a new node
        TreeNode* root=new TreeNode(postorder[postend]);
        ll inroot=m[postorder[postend]];
        ll count=inroot-instart;
        root->left=construct(inorder,instart,inroot-1,postorder,poststart,poststart+count-1,m);
        root->right=construct(inorder,inroot+1,inend,postorder,poststart+count,postend-1,m);

        return root;
    }
};