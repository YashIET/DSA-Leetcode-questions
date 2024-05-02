/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        
        ListNode* right=sortList(head->next);
        ListNode*left=head;
        ListNode *dummy=new ListNode();
        ListNode* newhead=dummy;
        while(left&& right){
            if(left->val<=right->val){
                newhead->next=left;
                newhead=newhead->next;
                left->next=right;
                break;
            }
            else{
                newhead->next=right;
                right=right->next;
                newhead=newhead->next;
                if(right==NULL){newhead->next=left;left->next=NULL;break;}
            }
            
        }
        
        return dummy->next;
    }
};