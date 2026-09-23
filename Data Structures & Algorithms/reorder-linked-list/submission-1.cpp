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
    ListNode* reverse(ListNode* head){
        ListNode* pre=NULL,*cur=head;
        while(cur!=NULL){
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        ListNode * slow= head, * fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l2=slow->next;
        slow->next=NULL;
         l2=reverse(l2);
        ListNode* l1=head;
        while(l1!=NULL&&l2!=NULL){
            ListNode* temp1=l1->next;
            ListNode* temp2=l2->next;
            l2->next=NULL;
            l1->next=l2;
            l2->next=temp1;
            l1=temp1;
            l2=temp2;
        }
      
    } 
};
