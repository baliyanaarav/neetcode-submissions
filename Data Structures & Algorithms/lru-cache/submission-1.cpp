class LRUCache {
    class Node{
        public:
        int data;
        int key;
        Node* prev;
        Node* next;
        Node(int k,int d){
            this->key=k;
            this->data =d;
            this->prev=NULL;
            this->next=NULL;
        }};
        Node* insertathead(Node *&head, int key,int v,Node* &tail){
            Node* temp = new Node(key, v);
            temp->next=head;
            if(head){
                head->prev=temp;
            }
            head=temp;
            if(tail==NULL)
            tail=head;
            return head;
        }
        void deletenode(Node* temp,Node* &tail){
         if(temp->prev){
            temp->prev->next=temp->next;
            if(temp->next){
                temp->next->prev=temp->prev;
            }
         }
         if(tail==temp){
         tail=temp->prev;
         }
         if(temp==head)
         head=temp->next;
         delete temp;
        }
    unordered_map<int,Node*>um;
public:
     int max_cap;
     int count;
     Node *head,*tail;
    LRUCache(int capacity) {
        max_cap=capacity;
         head =NULL;
        tail=NULL;
         count=0;
    }
    
    int get(int key) {
        if(um.find(key)==um.end()){
            return -1;
        }
        int a = um[key]->data;
       deletenode(um[key],tail);
      Node* temp= insertathead(head,key,a,tail);
      um[key]=temp;
      return a;

    }
    
    void put(int key, int value) {
        if(um.find(key)!=um.end()){
          deletenode(um[key],tail);
          Node* t=insertathead(head,key, value,tail);
          um[key]=t;
          return;
                  }
        count++;
        if(count>max_cap){
            int key=tail->key;
            um.erase(key);
            deletenode(tail,tail);
            
            count--;
        }
         Node* t=insertathead(head,key, value,tail);
          um[key]=t;
          return;
        
    }
};
