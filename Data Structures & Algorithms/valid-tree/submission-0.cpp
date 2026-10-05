class Solution {
public:
    bool checkinbfs(vector<bool>&visited,vector<vector<int>>&adj, int i){
        queue<int>q;
        q.push(i);
        unordered_map<int,int>um;
        um[i]=i;
        visited[i]=true;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto i:adj[a]){
                if(i == um[a]) continue;
                if(um.find(i)!=um.end()&&um[i]!=a){
                    return false;
                }
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    um[i]=a;
                }
            }

        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if((n-1)!=edges.size())
        return false;
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        bool check = checkinbfs(visited,adj,0);
        if(!check)
        return check;
        for(int i=0;i<n;i++){
            if(!visited[i])
            return false;
        }
        return true;
    }
};
