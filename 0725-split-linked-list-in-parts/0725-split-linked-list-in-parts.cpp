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
    typedef int ll;
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ll cnt=0;
        ListNode * temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        ll each_size=cnt/k;
        ll rem=cnt%k;
        vector<ListNode*>ans(k,NULL);
        temp=head;
        ListNode* pre=nullptr;
        for(ll i=0;temp && i<k;i++){
            ans[i]=temp;
            for(ll j=0;j<each_size;j++){
                pre=temp;
                temp=temp->next;
            }
            
            if(rem>0){
                pre=temp;
                temp=temp->next;
                rem--;
            }
            pre->next=nullptr;
        
            
        }
        return ans;
    }
};