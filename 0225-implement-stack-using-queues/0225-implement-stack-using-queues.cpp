class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            return -1;
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        if (q.empty()) {
            return -1;
        }
        return q.front();
    }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */