class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        for(int i=0;i<strs.size();i++){
            int count[26]={0};
            for(char c:strs[i]){
                count[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(count[i])+'#';
            }
            um[key].push_back(strs[i]);
        }
        vector<vector<string>>ans;
       for(auto i:um){
      ans.push_back(i.second);
       }
       return ans;
    }
};
