class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        int mini=val;
        if(!st.empty()){
         mini=min(mini,st.top().second);
        }
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if(st.empty())
        return -1;
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty())
        return -1;
        return st.top().second;
    }
};
