class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>um;
        int st=0,end=0,ans=0;
        while(end<s.size()){
            if(um.find(s[end])!=um.end()){
                ans=max(ans,end-st);
         while(um.find(s[end])!=um.end()){
            um.erase(s[st]);
            st++;
         }}
            um[s[end]]=1;
         end++;
      
        }
        ans=max(ans,end-st);
        return ans;
    }
};
