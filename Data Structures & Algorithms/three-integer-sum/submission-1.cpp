class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size()-2;i++){
        if(i > 0 && nums[i] == nums[i-1])
    continue;
        int a= nums[i];
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){
            if(a+nums[left]+nums[right]==0){
                ans.push_back({nums[left],nums[right],a});
                left++;
                right--;
                while(left<right&&nums[left-1]==nums[left])
                left++;
                while(right>left&&nums[right+1]==nums[right])
                right--;
            }
            else if(a+nums[left]+nums[right]>0){
               right--;
            }
            else{
                    left++;
            }
        }
     }   
            return ans;
    }
};
