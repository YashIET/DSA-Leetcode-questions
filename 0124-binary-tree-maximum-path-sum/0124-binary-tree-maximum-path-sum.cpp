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
    ll rec(TreeNode* root , ll &maxi){
        if(root==NULL)return 0;
        ll left = max(rec(root->left,maxi),0);
        ll right =max(rec(root->right,maxi),0);
       
        maxi = max(maxi,root->val+left+right);
        // cout<<root->val<<" "<<left<<" "<<right<<" "<<maxi<<endl;
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        ll maxi=INT_MIN;
        ll ans = rec(root,maxi);
        
        return maxi;
        
    }
};