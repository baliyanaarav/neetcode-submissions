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
    void insert(ListNode* &tail, ListNode* temp){
        tail->next=temp;
        tail=temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead= new ListNode(-1);
        ListNode* tail= newHead;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<list2->val){
                ListNode* temp = list1;
                 list1=list1->next;
                insert(tail,temp);
               
            }
            else{
                 ListNode* temp = list2;
                  list2=list2->next;
                insert(tail,temp);
               
            }
        }
        if(list1!=NULL){
            tail->next=list1;
        }
        if(list2!=NULL){
            tail->next=list2;
        }
        return newHead->next;
    }
};
