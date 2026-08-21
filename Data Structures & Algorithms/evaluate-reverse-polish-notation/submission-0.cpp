class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int ans=0;
        for(int i =0;i<tokens.size();i++){
          if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
            string op = tokens[i];
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            int tp;
            if(op=="+"){
              tp=stoi(a)+stoi(b);
            }
            else if(op=="-"){
 tp=stoi(b)-stoi(a);
            }
            else if(op=="*"){
tp=stoi(b)*stoi(a);
            }
            else{
tp=stoi(b)/stoi(a);
            }
            st.push(to_string(tp));
          }
          else{
            st.push(tokens[i]);
          }

        }
        return stoi(st.top());
    }
};
