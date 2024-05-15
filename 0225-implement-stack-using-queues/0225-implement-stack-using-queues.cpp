class MyStack {
public:
    queue<int>q;
    int t;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        t = x;
    }
    
    int pop() {
        queue<int>q2;
        while(q.size() > 1) {
            t = q.front(); q.pop();
            q2.push(t);
        }
        int x = q.front(); q.pop();
        q = q2;
        return x;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */