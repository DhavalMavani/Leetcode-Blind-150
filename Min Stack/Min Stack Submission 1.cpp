

class MinStack
{
public:
    stack<int> s1, min;

    void push(int val)
    {
        if (s1.empty())
        {
            s1.emplace(val);
            min.emplace(val);
        }
        else
        {
            min.emplace(std::min(min.top(), val));
            s1.emplace(val);
        }
    }

    void pop()
    {
        s1.pop();
        min.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return min.top();
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