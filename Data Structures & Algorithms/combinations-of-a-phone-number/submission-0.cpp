class Solution {
public:
  vector <string> keypad ={"","","abc","def","ghi","jkl","mno"
        ,"pqrs","tuv","wxyz"};
        vector<string>ans;
    void solve(string digits, int in , int n, string &cur){
        if(in==n){
          ans.push_back(cur);
          return;
        }
        string letters = keypad[digits[in]-'0'];
        for(char ch:letters){
            cur.push_back(ch);
            solve(digits,in+1,n,cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      if(digits.size()==0)
      return {};
      string cur="";
       solve(digits,0,digits.size(),cur);
       return ans;
    }
};
