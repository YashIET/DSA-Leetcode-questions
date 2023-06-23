/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:typedef int ll;

    Node* connect(Node* root) {
        queue<Node*>q;
        // q.push(NULL);
        if(!root)return root;
        q.push(root);
        while(!q.empty()){
            ll n=q.size();
            Node* temp=q.front();
            // st.pop();
            for(ll i=0;i<n;i++){
                temp=q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                if(i!=n-1)
                temp->next=q.front();
                else temp->next=NULL;
            }

        }
        return root;
    }
};