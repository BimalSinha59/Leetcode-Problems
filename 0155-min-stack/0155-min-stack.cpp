class MinStack {
public:
    stack<int>st;
    int mini;
    MinStack() {
    }
    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push( value );
            return;
        }
        if(value > mini) {
            st.push(value);
        }
        else {
            st.push(2 * value - mini);
            mini = value;
        }
    }
    void pop() {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2 * mini - x;
        }
    }
    int top() {
        if(st.empty()) return -1;
        int x = st.top();
        if(mini < x) return x;
        return mini;
    }
    int getMin() {
        return mini;
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