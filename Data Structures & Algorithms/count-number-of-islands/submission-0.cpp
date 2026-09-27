class Solution {
public:
     int ans=0;
     void visit(vector<vector<char>>& grid, vector<vector<bool>>&visited, int i, int j, int m, int n ){
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||grid[i][j]=='0')
        return ;
        visited[i][j]=true;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            visit(grid,visited,i+x[k],j+y[k],m,n);
        }

     }
    int numIslands(vector<vector<char>>& grid) {
       vector<vector<bool>>visited(grid.size(),vector(grid[0].size(),false));
       for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                  visit(grid,visited,i,j,grid.size(),grid[i].size());
                  ans++;
                }
            }
       } 
       return ans;
    }
};
