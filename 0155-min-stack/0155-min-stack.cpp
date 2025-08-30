class MinStack {
public:
    stack<int> st,min_val;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_val.push(val);
        }
        else{
            if(min_val.top()>=val){
                min_val.push(val);
            }
            else{
                min_val.push(min_val.top());
            }
            st.push(val);
        }
        
    }
    
    void pop() {
        st.pop();
        min_val.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return min_val.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */