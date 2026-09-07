class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n==1)
       return nums[0];
       if(n==2)
       return max(nums[0],nums[1]);
       int pre2=nums[0],pre1=max(nums[1],nums[0]);
       for(int i=2;i<n;i++){
            int temp=max(pre2+nums[i],pre1);
            pre2=pre1;
            pre1=temp;
       }
       return pre1;
    }
};
