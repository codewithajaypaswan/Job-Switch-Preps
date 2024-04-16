class MyCircularQueue {
public:
    vector<int>arr;
    int front, rear, size, cnt;
    MyCircularQueue(int k) {
        arr.resize(k);
        size = k, front = rear = 0, cnt = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1)%size;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1)%size;
        cnt--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[(rear - 1 + size)%size];
    }
    
    bool isEmpty() {
        if(cnt == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(cnt == size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */