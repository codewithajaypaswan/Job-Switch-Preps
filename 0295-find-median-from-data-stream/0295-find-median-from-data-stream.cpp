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
            int x = mn.top(); mn.pop();
            if(num > x) {
                mn.push(num);
                mx.push(x);
            }
            else {
                mn.push(x);
                mx.push(num);
            }
        }
        else {
            int x = mx.top(); mx.pop();
            if(num < x) {
                mx.push(num);
                mn.push(x);
            }
            else {
                mn.push(num);
                mx.push(x);
            }
        }
    }
    
    double findMedian() {
        if((mx.size() + mn.size())%2 == 1) {
            return (double)mx.top();
        }
        else {
            return (double) (mn.top() + mx.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */