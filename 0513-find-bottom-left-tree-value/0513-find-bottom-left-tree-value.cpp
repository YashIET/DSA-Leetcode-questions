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
    ll maxr=-1,minc=INT_MAX;
    TreeNode* ans;
    void find(ll row,ll col,TreeNode* root){
        // if(root->left==NULL && root->right==NULL){
        //     if(row>=maxr && col>=minc)return root;
        //     else return NULL;
        // }
        // if(root->left)
        if(row>maxr)ans=root;
        maxr=max(row,maxr);
        minc=min(minc,col);
        if(row>=maxr){
            
            if(col<=minc)ans=root;
        }
        if(root->left)find(row+1,col-1,root->left);
        if(root->right)find(row+1,col+1,root->right);
    }
    int findBottomLeftValue(TreeNode* root) {
        find(0,0,root);
        return ans->val;
    }
};