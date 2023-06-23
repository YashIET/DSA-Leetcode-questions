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
    void inorder(TreeNode* root,ll &cnt,ll k , ll&ans){
        if(root==NULL)return;
        
        inorder(root->left , cnt , k , ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        inorder(root->right , cnt , k , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<ll>ans;
        ll count=0;
        ll ans;
        inorder(root,count,k,ans);
        return ans; 

    }
};