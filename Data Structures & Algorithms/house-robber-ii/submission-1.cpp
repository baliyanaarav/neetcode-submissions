class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);
        return max(robb(nums,0,n-2), robb(nums,1,n-1));
    }
    int robb(vector<int>&nums, int start, int end){
        int pre2=nums[start],pre1=max(nums[start+1],nums[start]);
        for(int i=start+2;i<=end;i++){
            int temp=max(pre1,pre2+nums[i]);
            pre2=pre1;
            pre1=temp;
        }
        return pre1;
    }
};
