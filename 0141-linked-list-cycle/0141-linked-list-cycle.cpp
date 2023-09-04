/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 typedef int ll;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow,*fast;

        slow=fast=head;
        if( fast==NULL || fast->next ==NULL )return false;
        slow=slow->next;
        fast=fast->next->next;
        while(slow!=fast && slow!=NULL){
        slow=slow->next;
        if( fast==NULL || fast->next ==NULL )return false;
        fast=fast->next->next;
            
        }
        if(slow==NULL)return false;
        return true;
    }
};