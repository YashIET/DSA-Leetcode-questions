/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    typedef int ll;
    Node* copyRandomList(Node* head) {
    //    unordered_map<Node*,Node*>m;
        Node* temp=head;
        while(temp){
            Node* t2=new Node(temp->val);
            // m[temp]=t2;
            // t2->val=temp->val;
            // temp=temp->next;
            t2->next=temp->next;
            temp->next=t2;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            // Node* nx=temp->next;
            // Node* rnd=temp->random;
            // Node * t2=m[temp];
            // t2->next=m[temp->next];
            // t2->random=m[temp->random];
            // temp=temp->next;
            if(temp->random)
            temp->next->random=temp->random->next;
            // else temp->next->random=NULL;
            temp=temp->next->next;
        }
        temp=head;
        Node *dummy=new Node(0);
        Node *copy=dummy;
        Node *front;

        while(temp){
            // if(temp->next&&temp->next->next)
            front=temp->next->next;
            copy->next=temp->next;
            temp->next=front;
            copy=copy->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};