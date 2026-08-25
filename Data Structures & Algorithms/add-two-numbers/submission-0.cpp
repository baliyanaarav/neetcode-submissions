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
    void insert(ListNode* &tail, int d){
        ListNode * temp = new ListNode(d);
        tail->next=temp;
        tail=temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&l2==NULL)
        return NULL;
        else if(l1==NULL){
            return l2;
        }
        else if(l2==NULL)
        return l1;
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;
        int carry=0;
        while(l1!=NULL&&l2!=NULL){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            int te=sum%10;
            insert(tail,te);
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL)
        l1=l2;
        while(l1!=NULL){
            int sum = l1->val+carry;
            carry=sum/10;
            insert(tail,sum%10);
            l1=l1->next;
        }
        if(carry!=0){
            insert(tail,carry);
        }
        return newHead->next;
    }
};
