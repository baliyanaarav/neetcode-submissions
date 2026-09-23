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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head, *fast=head,* pre=NULL;
        int c=0;
        while(fast!=NULL&&c<n){
            fast=fast->next;
            c++;
        }
        while(fast!=NULL){
            pre=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(pre==NULL)
        return head->next;
        pre->next=pre->next->next;
        return head;
    }
};
