class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int k=0;k<4;k++){
                int nr=r+x[k];
                int nc=c+y[k];
                if(nr<0||nc<0||nr>=m||nc>=n)
                continue;
                if(grid[nr][nc]!=INT_MAX)
                continue;
                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});
            }
        }

    }
};
