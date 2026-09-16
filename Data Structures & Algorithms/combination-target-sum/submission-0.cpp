class Solution {
public:
    vector<vector<int>>ans;
    void finds(vector<int>& nums, int in, int target, int sum, vector<int>&curr){
     if(sum==target){
         ans.push_back(curr);
         return;
     }
     if(in==nums.size()||sum>target){
        return;
     }
     finds(nums,in+1,target,sum,curr);
     sum=sum+nums[in];
     curr.push_back(nums[in]);
     finds(nums,in,target,sum,curr);
     sum=sum-nums[in];
     curr.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        finds(nums,0,target,0,curr);
        return ans;
    }
};
