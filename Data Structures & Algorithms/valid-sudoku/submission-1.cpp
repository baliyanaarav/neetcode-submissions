class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>us;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                continue;
                string col=to_string(board[i][j])+"COL"+to_string(j);
                 string row=to_string(board[i][j])+"ROW"+to_string(i);
                  string box=to_string(board[i][j])+"BOX"+to_string((i/3)*3+(j/3));
                  if(us.find(col)!=us.end()||us.find(row)!=us.end()||us.find(box)!=us.end()){
                    return false;
                  }
                  us.insert(col);
                  us.insert(row);
                  us.insert(box);
            }
        }
        return true;
    }
};
