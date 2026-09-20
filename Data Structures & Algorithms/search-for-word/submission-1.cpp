class Solution {
public:
    bool helper(vector<vector<char>>& board, int i, int j, int m,int n, string word, int k){
        if(k>=word.size())return true;
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='.'||word[k]!=board[i][j])return false;
        if(word.size()==1&&word[k]==board[i][j])
        return true;
        board[i][j]='.';
        bool temp=false;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        for(int q=0;q<4;q++){
            temp=temp||helper(board,i+x[q],j+y[q],m,n,word,k+1);
        }
        board[i][j]=word[k];
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0||board.size()==0)
        return false;
        int m=board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board,i,j,m,n,word,0)) return true;
            }
        }
        return false;
        
    }
};
