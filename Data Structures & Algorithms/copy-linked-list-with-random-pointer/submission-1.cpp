/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>um;
    Node* copyRandomList(Node* head) {
        Node* nhead=new Node(-1);
        Node* tail =nhead;
        Node* temp=head;
        while(temp!=NULL){
            Node* nn = new Node(temp->val);
            tail->next=nn;
            tail=nn;
            um[temp]=nn;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            um[temp]->random=um[temp->random];
            temp=temp->next;
        }
        return nhead->next;
    }
};
