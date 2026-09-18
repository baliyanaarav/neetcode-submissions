class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>& nums,vector<bool>&used, vector<int>&cur ){
       if(nums.size()==cur.size()){
        ans.push_back(cur);
        return;
       }
       for(int i=0;i<nums.size();i++){
        if(used[i])
        continue;
        used[i]=true;
        cur.push_back(nums[i]);
        find(nums,used,cur);
        used[i]=false;
        cur.pop_back();
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        vector<int>cur;
        find(nums,used,cur);
        return ans;
    }
};
