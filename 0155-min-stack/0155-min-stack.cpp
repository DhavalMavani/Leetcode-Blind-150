class MinStack {
public:
    stack<pair<int,int>> st;
    long long minVal=LLONG_MIN;

    void push(int val) {
        if(minVal==LLONG_MIN) minVal=val;
        else minVal=min((long long)val,minVal);
        st.push({val,minVal});
    }
    
    void pop() {
        st.pop();
        if(!st.empty()) minVal=st.top().second;
        else minVal=LLONG_MIN;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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