class Solution {
public:
    void visit(vector<vector<int>>& grid, int m, int n,int i,int j, int &count){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0)
        return;
        grid[i][j]=0;
        count++;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            visit(grid,m,n,i+x[k],j+y[k],count);
        }

    }
    int ans=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int m = grid.size();
     int n=grid[0].size();
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int count=0;
            visit(grid,m,n,i,j,count);
            if(ans<count)
            ans=count;
            }
        }
     }
    return ans;
    }
};
