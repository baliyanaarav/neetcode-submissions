class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='S';
            }
            if((n-1)!=0&&board[i][n-1]=='O'){
                q.push({i,n-1});
                board[i][n-1]='S';
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='S';
            }
            if((m-1)!=0&&board[m-1][i]=='O'){
                q.push({m-1,i});
                board[m-1][i]='S';
            }
        }
        int x[4]={0,0,1,-1};
        int y[4]={-1,1,0,0};
        while(!q.empty()){
            pair<int,int>pt=q.front();
            q.pop();
            int r= pt.first;
            int c=pt.second;
            for(int k=0;k<4;k++){
                int nr=r+x[k];
                int nc=c+y[k];
                if(nr<0||nc<0||nr>=m||nc>=n)
                continue;
                if(board[nr][nc]!='O')
                continue;
                board[nr][nc]='S';
                q.push({nr,nc});

            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='S')
                board[i][j]='O';
            }
        }
    }
};
