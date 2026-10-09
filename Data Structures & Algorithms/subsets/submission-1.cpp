class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&nums, int i, int n, vector<int>&cur){
        if(i==n){
            ans.push_back(cur);
            return ;
        }
        find(nums,i+1,n,cur);
        cur.push_back(nums[i]);
        find(nums,i+1,n,cur);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        find(nums,0,nums.size(),cur);
        return ans;
        
    }
};
