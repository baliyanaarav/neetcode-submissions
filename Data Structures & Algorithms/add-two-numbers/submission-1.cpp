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
    void append(ListNode* &tail , int a){
        ListNode * nn = new ListNode(a);
        tail->next=nn;
        tail=nn;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nhead= new ListNode(-1);
        ListNode* tail = nhead;
        int sum=0,carry=0;
        while(l1!=NULL&&l2!=NULL){
           sum=l1->val+l2->val+carry;
           append(tail,sum%10);
           carry=sum/10;
           l1=l1->next;
           l2=l2->next;
        }
        if(l2!=NULL)
        l1=l2;
        while(l1!=NULL){
            sum=l1->val+carry;
            append(tail,sum%10);
           carry=sum/10;
           l1=l1->next;
        }
        if(carry!=0){
            append(tail,carry);
        }
return nhead->next;
    }
};
