class Solution {
public:
vector<vector<int>>ans;
    void find(vector<int>& candidates, int target,int sum, vector<int>&curr, int index){
        if(target==sum){
    ans.push_back(curr);
    return;
   }
   if(index==candidates.size()){
    return ;
   }
   if(target<sum){
    return;
   }
           int j = index;
        while (j < candidates.size() && candidates[j] == candidates[index]) j++;

   find(candidates,target,sum,curr,j);
   sum=sum+candidates[index];
   curr.push_back(candidates[index]);
   find(candidates,target,sum,curr,index+1);
    curr.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>cur;
        find(candidates,target,0,cur,0);
        return ans;
    }
};
