class Solution {
public:
    vector<string>ans; 
    void find(int n,int op, int cl, string cur){
        if(op+cl==2*n){
            ans.push_back(cur);
            return;
        }
        if(op<n){
            find(n,op+1,cl,cur+'(');
        }
        if(cl<op){
            find(n,op,cl+1,cur+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
       find(n,0,0,cur);
       return ans;
    }
};
