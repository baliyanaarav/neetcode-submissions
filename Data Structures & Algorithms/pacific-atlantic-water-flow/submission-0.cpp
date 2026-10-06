class Solution {
public:
    void bfs(vector<vector<bool>>&visited, vector<vector<int>>& heights, queue<pair<int,int>>&q ){
      int x[4]={0,0,1,-1};
      int y[4]={1,-1,0,0};
      while(!q.empty()){
        pair<int,int>p=q.front();
        int r=p.first;
        int c=p.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+x[i];
            int nc=c+y[i];
            if (nr < 0 || nr >= heights.size() ||
    nc < 0 || nc >= heights[0].size())
    continue;
              if(heights[nr][nc]<heights[r][c])
              continue;
              if(visited[nr][nc])
              continue;
              visited[nr][nc]=true;
              q.push({nr,nc});
        }
      }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
         queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;
         for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            pq.push({0,j});
        }

        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pq.push({i,0});
        }
        for (int j = 0; j < n; j++) {
            atlantic[m-1][j] = true;
            aq.push({m-1,j});
        }

        for (int i = 0; i < m; i++) {
            atlantic[i][n-1] = true;
            aq.push({i,n-1});
        }

        bfs( pacific, heights,pq);
        bfs( atlantic, heights, aq);
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
