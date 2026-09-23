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
    void append(ListNode* &tail , int d){
        ListNode* temp= new ListNode(d);
        tail->next=temp;
        tail=temp;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<=list2->val){
               append(tail,list1->val);
               list1=list1->next;
            }
            else{
                append(tail,list2->val);
                list2=list2->next;
            }
        }
        if(list2!=NULL)
        list1=list2;
        while(list1!=NULL){
            append(tail,list1->val);
            list1=list1->next;
        }
        return head->next;

    }
};
