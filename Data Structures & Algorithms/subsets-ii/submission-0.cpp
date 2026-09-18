class Solution {
public:
    vector<vector<int>>ans;
    void subsetii(vector<int>&nums,vector<int>&cur,int in, int n){
        if(in==n){
            ans.push_back(cur);
            return;
        }
        int j=in;
        while(j<n&&nums[j]==nums[in])
        j++;
        subsetii(nums,cur,j,n);
        cur.push_back(nums[in]);
        subsetii(nums,cur,in+1,n);
        cur.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>cur;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        subsetii(nums,cur,0,n);
        return ans;
    }
};
