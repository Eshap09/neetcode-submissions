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
        int minm = min(st.top().second,val);
        st.push({val,minm});
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        st.pop();
    }
    
    int top() { 
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
