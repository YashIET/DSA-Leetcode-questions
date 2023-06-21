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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*>q;
        if(root==NULL)return ans;
        q.push_back(root);
        ll k=0;
        while(!q.empty()){
            if(k&1){
                TreeNode* temp=q.back();
                ll n=q.size();
                vector<ll>temp2;
                for(ll i=0;i<n;i++){
                    temp=q.back();
                    q.pop_back();
                    temp2.push_back(temp->val);
                    if(temp->right)q.push_front(temp->right);
                    if(temp->left)q.push_front(temp->left);
                    

                }
                ans.push_back(temp2);
            }
            else{
                TreeNode* temp=q.front();
                ll n=q.size();
                vector<ll>temp2;
                for(ll i=0;i<n;i++){
                    temp=q.front();
                    q.pop_front();
                    temp2.push_back(temp->val);
                    if(temp->left)q.push_back(temp->left);
                    if(temp->right)q.push_back(temp->right);

                }
                ans.push_back(temp2);
            }
            k++;

        }
        return ans;
    }
};