class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int>us;
     for(auto it:nums){
      us.insert(it);
     }   
     int ans=0;
     for(auto it:us){
       if(us.find(it-1)==us.end()){
         int cn=1;
         int a=it;
         while(us.find(a+1)!=us.end()){
           a++;
           cn++;
         }
         ans=max(cn,ans);
       }
       
     }
     return ans;
    }
};
