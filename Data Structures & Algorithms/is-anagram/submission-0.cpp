class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        unordered_map<char,int>um;
        for(int i =0;i<s.size();i++){
            um[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(um.find(t[i])!=um.end()&&um[t[i]]>0){
                um[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
