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
    TreeNode * BST(vector<ll>&nums,ll left,ll right){
        if(left>right)return NULL;
        ll mid=(left+right)>>1;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=BST(nums,left,mid-1);
        root->right=BST(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *ans=BST(nums,0,nums.size()-1);
        return ans;
    }
};