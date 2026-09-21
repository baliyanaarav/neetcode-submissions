class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        unordered_set<char>us;
        int left=0, right=0,ans=INT_MIN;
        while(right<s.size()){
            while(us.find(s[right])!=us.end()){
               us.erase(s[left]);
               left++;
            }
            us.insert(s[right]);
            right++;

            ans=max(ans,right-left);
        }
        return ans;
    }
};
