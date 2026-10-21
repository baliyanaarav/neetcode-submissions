class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>need(128,0);
        for(char ch:t){
            need[ch]++;
        }
        int missing=t.size();
        int left=0,bl=INT_MAX,bs=0;
        string ans="";
        for(int r=0;r<s.size();r++){
            if(need[s[r]]-- >0)missing--;
            while(missing==0){
                if (r - left + 1 < bl) {
                    bs = left;
                    bl = r - left + 1;
                }
            if (++need[s[left]] > 0) missing++;

               left++;
            }
        }
        return bl == INT_MAX ? "" : s.substr(bs, bl);
    }
};
