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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> um;
        Node* newHead = new Node(-1);
        Node* tail = newHead;
        Node* temp = head;
        while(temp!=NULL){
            int d = temp->val;
            Node* newnode = new Node(d);
            tail->next=newnode;
            um[temp]=newnode;
            tail=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            um[temp]->random=um[temp->random];
            temp=temp->next;
        }
        return newHead->next;
    }
};
