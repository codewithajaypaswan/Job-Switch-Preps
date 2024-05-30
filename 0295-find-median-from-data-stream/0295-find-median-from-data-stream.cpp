class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int, vector<int>, greater<int>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty()) {
            mx.push(num);
        }
        else if(mx.size() == mn.size()) {
            if(num > mn.top()) {
                int x = mn.top(); mn.pop();
                mn.push(num);
                mx.push(x);
            }
            else {
                mx.push(num);
            }
        }
        else {
            if(num < mx.top()) {
                int x = mx.top(); mx.pop();
                mx.push(num);
                mn.push(x);
            }
            else {
                mn.push(num);
            }
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size()) {
            return (double)(mn.top() + mx.top())/2;
        }
        else return (double)mx.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */