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
 typedef int ll;
ll ans=0;
class NodeValue{
    public:
     ll mini,maxi,size,sum;
     NodeValue(ll mini,ll maxi,ll size,ll sum){
         this->mini=mini;
         this->maxi=maxi;
         this->size=size;
         this->sum=sum;
     }
    NodeValue(){}
 };
//link to understand better;
//------------https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/discuss/1126183/C%2B%2B-Recursion-or-Easy-to-understand//
class Solution {
public:
    NodeValue max_sum_BST(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0,0);
        }

        NodeValue left=max_sum_BST(root->left);
        NodeValue right=max_sum_BST(root->right);

        //check if valid bst
        if(left.maxi<root->val && root->val<right.mini ){
            ans = max(ans,left.sum+right.sum+root->val);
            return NodeValue(min(left.mini,root->val),max(right.maxi,root->val),left.size+right.size+1,(left.sum+right.sum+root->val ));
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size),max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        max(0,max_sum_BST(root).sum);
        return ans;
    }
};