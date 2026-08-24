class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
            return;
        }
        pair<int,int>a=st.top();
        st.push({val,min(val,a.second)});
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
        return;
    }
    
    int top() {
        if(st.empty())
        return -1;
       pair< int,int> a = st.top();
       return a.first;

    }
    
    int getMin() {
        pair<int,int>a=st.top();
        return a.second;
    }
};
