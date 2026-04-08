class FreqStack {
public:
    unordered_map<int, int> mp1;
    unordered_map<int, stack<int>> mp2;
    int mf = 0;
    FreqStack() {
    }
    
    void push(int val) {
        mp1[val]++;
        mf = max(mf, mp1[val]);
        mp2[mp1[val]].push(val);
    }
    
    int pop() {
        int x = mp2[mf].top();
        mp2[mf].pop();
        if (!mp2[mp1[x]--].size()){
            mf--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */