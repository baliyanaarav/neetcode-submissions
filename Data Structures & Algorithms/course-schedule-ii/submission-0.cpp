class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<int>ans;
     vector<int>indegree(numCourses,0);
     vector<vector<int>>adj(numCourses,vector<int>());
     for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
     }
     queue<int>q;
     for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)
        q.push(i);
     }
     while(!q.empty()){
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto i:adj[a]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
     }
     if(ans.size()==numCourses)
     return ans;
     return {};

    }
};
