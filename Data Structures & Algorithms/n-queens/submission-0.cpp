class Solution {
public:
    vector<vector<string>> ans;
    bool safe(vector<string> & board, int row, int col, int n){
           for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
            return false;
           }
           for(int i=row -1 , j= col-1 ;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
            return false;
           }
           for(int i=row -1 , j= col+1 ;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')
            return false;
           }
           return true;
    }
    void put(vector<string> &board, int n, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(safe(board,row,col,n)){
                board[row][col]='Q';
                put(board,n,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        put(board,n,0);
        return ans;
    }
};
