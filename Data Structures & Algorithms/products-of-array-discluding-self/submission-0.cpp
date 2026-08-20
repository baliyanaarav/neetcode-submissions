class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int prefix=1,suffix=1;
    vector<int>ans(nums.size(),1);
    for(int i =1;i<nums.size();i++){
     prefix=prefix*nums[i-1];
     ans[i]=prefix;
    }
    for(int i=nums.size()-2;i>=0;i--){
        suffix=suffix*nums[i+1];
        ans[i]=ans[i]*suffix;
    }
    return ans;
    }
};
