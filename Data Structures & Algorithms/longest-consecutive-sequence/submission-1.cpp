class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>us(nums.begin(),nums.end());
        int ans=0;
     for(auto i:us){
        int count=1;
        if(us.find(i-1)==us.end()){
         while(us.find(i+1)!=us.end()){
            count++;
            i++;
         }
         ans=max(ans,count);
        }
     }
     return ans;
    }
};
