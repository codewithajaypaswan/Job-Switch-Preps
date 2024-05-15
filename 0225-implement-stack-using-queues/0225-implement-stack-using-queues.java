class MyStack {
    Queue<Integer> q1 = new LinkedList<>();
    int temp;
    public MyStack() {
        
    }
    
    public void push(int x) {
        q1.add(x);
        temp = x;
    }
    
    public int pop() {
        Queue<Integer> q2 = new LinkedList<>();
        while(q1.size() > 1) {
            temp = q1.peek();
            q2.add(q1.poll());
        }
        int x = q1.poll();
        q1 = q2;
        return x;
    }
    
    public int top() {
        return temp;
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */