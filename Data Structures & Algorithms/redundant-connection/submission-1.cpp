class Solution {
public:
    int find(vector<int>&parent, int x){
        if(parent[x]==x)
        return x;
        return find(parent,parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            int pu=find(parent,u);
            int pv=find(parent,v);
            if(pu==pv)
            return edges[i];
            parent[pu]=pv;
        }
    }
};
