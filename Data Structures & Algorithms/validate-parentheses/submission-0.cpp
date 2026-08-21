class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(st.empty()&&(ch==']'||ch=='}'||ch==')'))
            return false;
            else if(ch=='('||ch=='['||ch=='{')
            st.push(ch);
            else if((st.top()=='('&&ch==')')||(st.top()=='['&&ch==']')||(st.top()=='{'&&ch=='}'))
            st.pop();
            else
            return false;

        }
        return st.empty();
    }
};
