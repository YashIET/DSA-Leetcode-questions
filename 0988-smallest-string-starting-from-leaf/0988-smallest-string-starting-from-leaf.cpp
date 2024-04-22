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
class Solution {
public:
    map<ll,string>index;
    map<string,ll>m;
    
    void rec(TreeNode* root,string s){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            string temp=s+index[root->val];
            reverse(temp.begin(),temp.end());
            m[temp]++;
            return ;
        }
        rec(root->left,s+index[root->val]);
        rec(root->right,s+index[root->val]);
    } 
    
    string smallestFromLeaf(TreeNode* root) {
        for(ll i=0;i<26;i++){
        index[i]=i+'a';
            // cout<<index[i]<<" ";
            }
        rec(root,"");
        string ans;
        for(auto it:m){
            ans=it.first;
            // cout<<ans<<" ";
            break;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};