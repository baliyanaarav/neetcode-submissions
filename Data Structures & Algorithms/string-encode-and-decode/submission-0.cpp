class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(int i =0;i<strs.size();i++){
            encoded+=to_string(strs[i].size())+'#'+strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>ans;
       for(int i=0;i<s.size();i++){
         int j=i;
         while(s[j]!='#'){
            j++;
         }
        int l = stoi(s.substr(i,j-i));
        ans.push_back(s.substr(j+1,l));
        i=j+l;
       }
       return ans;
    }
};
