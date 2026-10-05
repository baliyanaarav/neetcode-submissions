class Solution {
public:
    void bfs(int node, vector<bool>&visited,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(auto i:adj[a]){
                if(!visited[i]){
                q.push(i);
                visited[i]=true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n,vector<int>());
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
            bfs(i,visited,adj);
            }
        }
        return ans;
    }
};
