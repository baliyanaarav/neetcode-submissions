class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)
        return false;
        stack<char>st;
        for(char ch:s){
            if(st.empty()&&(ch==')'||ch==']'||ch=='}'))
            return false;
            else if(ch=='('||ch=='{'||ch=='[')
            st.push(ch);
            else if((ch==')'&&st.top()=='(')||(ch==']'&&st.top()=='[')||(ch=='}'&&st.top()=='{'))
            st.pop();
            else
            return false;
        }
        return st.empty();
    }
};
