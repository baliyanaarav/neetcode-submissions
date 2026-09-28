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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        return NULL ;
        int c=0;
        ListNode* temp=head;
        while(c<k){
            if(temp==NULL)
            return head;
            temp=temp->next;
            c++;
        }
        ListNode* t1=reverseKGroup(temp,k);
        
        ListNode* pre=NULL,*cur=head;
        while(cur!=temp){
            ListNode* n1=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n1;
        }
        head->next=t1;
        return pre;

    }
};
