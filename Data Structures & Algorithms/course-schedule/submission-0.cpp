class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int>q;
        int completed=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
          int a =q.front();
          q.pop();
          completed++;
          for(auto i :adj[a]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
          }
        }
        return numCourses==completed;

    }
};
