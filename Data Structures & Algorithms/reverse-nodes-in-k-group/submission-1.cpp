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
        return NULL;
        ListNode* temp=head;
        for(int i=0;i<k;i++){
             if(temp==NULL)
             return head;
             temp=temp->next;
        }
        ListNode* n1=reverseKGroup(temp,k);
        ListNode* pre=NULL,*cur=head;
        while(cur!=temp){
            ListNode* t1=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t1;
        }
        head->next=n1;
        return pre;
    }
};
