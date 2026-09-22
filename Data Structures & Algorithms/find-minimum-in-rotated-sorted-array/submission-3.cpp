class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r= nums.size()-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(nums[l]<=nums[mid]){
              ans=min(ans,nums[l]);
              l=mid+1;
            }
            else{
              ans=min(ans,nums[mid+1]);
              r=mid;
            }
        }
        return ans;
    }
};
