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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<ll>>ans;
        queue<TreeNode*>q;
        if(root==NULL)return ans;
        q.push(root);
        

        while(!q.empty()){
            ll n=q.size();
            vector<ll>temp;
            for(ll i=0;i<n;i++){
                // if(n==0)return ans;
                TreeNode* node=q.front();
                q.pop(); 
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right)q.push(node->right);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};