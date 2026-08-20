class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        for(int i =0;i<strs.size();i++){
            string key = strs[i];
          sort(key.begin(),key.end());
            um[key].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:um){
           ans.push_back(i.second);
        }
        return ans;
    }
};
