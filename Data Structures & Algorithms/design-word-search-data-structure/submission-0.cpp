class Node{
    public:
char ch;
Node* next[26];
bool isEnd;
Node(char c){
    this->isEnd=false;
    this->ch=c;
for(int i=0;i<26;i++){
    this->next[i]=NULL;
}}
};
class WordDictionary {
public:
Node* root;
    WordDictionary() {
        root=new Node('#');
    }
    
    void addWord(string word) {
        Node* cur=root;
        for(char ch:word){
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
    bool dfs(string word, int index , Node* root){
        if(index==word.size()){
            return root->isEnd==true;
        }
           char ch= word[index];
           if(ch=='.'){
        
            for(int i=0;i<26;i++){
                if(root->next[i]){
                if(dfs(word,index+1,root->next[i]))
                return true;}
            }
           }
           else{
            int i = ch-'a';
            if(!root->next[i])
            return false;
             return dfs(word,index+1,root->next[i]);
           }
           return false;
    }
    bool search(string word) {
      return dfs(word,0,root);
    }
};
