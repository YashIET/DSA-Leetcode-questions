/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef int ll;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;//for storing parent
        // m[root]=NULL;
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            
            auto it=q1.front();
            q1.pop();
            if(it->left){
                q1.push(it->left);
                m[it->left]=it;
            }
            if(it->right){
                q1.push(it->right);
                m[it->right]=it;
            }
        }
        //we have got our parent map
        //now we just need to travers in three ways and stop when distance equals to k
        ll dis=0;
        queue<TreeNode*>q;
        map<TreeNode*,ll>visited;
        q.push(target);
        visited[target]=1;
        while(!q.empty()){
            ll len=q.size();
            if(dis++==k)break;
            
            for(ll i=0;i<len;i++){
                auto it=q.front();
                q.pop();
                if(it->left && !visited[it->left]){
                    q.push(it->left);
                    visited[it->left]=1;
                }
                if(it->right && !visited[it->right]){
                    q.push(it->right);
                    visited[it->right]=1;
                }
                if(m[it] && !visited[m[it]]){
                    q.push(m[it]);
                    visited[m[it]]=1;
                }
                
            }
            // if(dis==k)break;
            
        }
        vector<ll>ans;
        ll qlen=q.size();
            for(ll i=0;i<qlen;i++){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
    }
};