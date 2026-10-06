class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
         int m = grid.size(),n=grid[0].size();
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
         }
         int minute=0;
         int x[4]={0,0,1,-1};
         int y[4]={1,-1,0,0};
         while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
               pair<int,int>pt=q.front();
                    int r = pt.first;
                    int c=pt.second;
                    
               q.pop();
               for(int i=0;i<4;i++){
                int nr=r+x[i];
                int nc=c+y[i];
                if(nr<0||nc<0||nr>=grid.size()||nc>=grid[0].size())
                continue;
               
               if(grid[nr][nc]==2||grid[nr][nc]==0)
               continue;
               grid[nr][nc]=2;
               fresh--;
               q.push({nr,nc});}
            }
            if(!q.empty())
            minute++;
            
         }
         return fresh==0?minute:-1;
    }
};
