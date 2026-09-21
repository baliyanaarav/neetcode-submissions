class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        unordered_map<char,int>um;
        for(auto ch:s){
            um[ch]++;
        }
        for(auto ch:t){
            if(um[ch]>0){
                um[ch]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
