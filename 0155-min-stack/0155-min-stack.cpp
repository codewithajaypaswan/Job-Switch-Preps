class MinStack {
public:
    stack<int>s1;
    int minEle = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(val <= minEle) {
            s1.push(minEle);
            minEle = val;
        }
        s1.push(val);
    }
    
    void pop() {
        if(s1.top() == minEle) {
            s1.pop();
            minEle = s1.top();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return minEle;
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