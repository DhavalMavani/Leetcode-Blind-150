class CustomStack {
public:
    vector<int> st;
    int curr=0;
    CustomStack(int maxSize) {
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(curr==st.size()) return;
        st[curr++]=x;
    }
    
    int pop() {
        if(curr==0) return -1;
        return st[--curr];
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,curr);i++) st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */