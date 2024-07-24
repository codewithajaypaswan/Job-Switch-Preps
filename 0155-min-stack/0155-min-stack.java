class MinStack {
    Stack<Integer>st = new Stack();
    int minEle = Integer.MAX_VALUE;
    public MinStack() {
        
    }
    
    public void push(int val) {
        if(val <= minEle) {
            st.push(minEle);
            minEle = val;
        }
        st.push(val);
    }
    
    public void pop() {
        if(minEle == st.peek()) {
            st.pop();
            minEle = st.peek();
        }
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minEle;
    }
}

/*

class MinStack {
    Stack<Integer>st = new Stack();
    Stack<Integer>min = new Stack();
    public MinStack() {
        
    }
    
    public void push(int val) {
        if(st.isEmpty()) {
            st.push(val);
            min.push(val);
        }
        else {
            st.push(val);
            min.push(Math.min(min.peek(), val));
        }
    }
    
    public void pop() {
        st.pop();
        min.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return min.peek();
    }
}


*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */