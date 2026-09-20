class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>um;
        for(int i=0;i<strs.size();i++){
            vector<int>chs(26,0);
            for(int j=0;j<strs[i].size();j++){
                chs[strs[i][j]-'a']++;
            }
            string key="";
            for(int k=0;k<26;k++){
                key+=(to_string(chs[k])+"#");
                
            }
            um[key].push_back(strs[i]);
        }
        for(auto i:um){
            ans.push_back(i.second);
        }
        return ans;
    }
};
