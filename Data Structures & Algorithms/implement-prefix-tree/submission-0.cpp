class Node{
public:
char ch;
Node* next[26];
bool isEnd;
Node(char c){
    this->ch=c;
    for(int i=0;i<26;i++)
    next[i]=NULL;
    isEnd=false;
}
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
      root=new Node('#');  
    }
    
    void insert(string word) {
        Node* cur=root;
        for(char ch: word){
            int index=ch-'a';
             Node* temp=cur->next[index];
            if(temp==NULL){
                temp= new Node(ch);
                cur->next[index]=temp;
            }
            cur=temp;
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        Node* cur=root;
        for(char ch: word){
            int i=ch-'a';
           if(cur->next[i]==NULL)
           return false;
           cur=cur->next[i];
        }
        return cur->isEnd==true;
    }
    
    bool startsWith(string prefix) {
         Node* cur=root;
        for(char ch: prefix){
            int i=ch-'a';
           if(cur->next[i]==NULL)
           return false;
           cur=cur->next[i];
        }
        return true;
    }
};
