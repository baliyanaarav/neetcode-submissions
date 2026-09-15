class Solution {
public:
    vector<vector<int>>ans;
    void findsub(vector<int> nums,int i,int n, vector<int>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        findsub(nums,i+1,n,temp);
        temp.push_back(nums[i]);
        findsub(nums,i+1,n,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        findsub(nums,0,nums.size(),temp);
        return ans;
    }
};
