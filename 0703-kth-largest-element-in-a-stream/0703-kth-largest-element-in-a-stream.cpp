class KthLargest {
public:
    int size;
    priority_queue<int>pq;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int x:nums) {
            pq.push(-x);
            if(pq.size() > size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size() > size) pq.pop();
        return -1 * pq.top();
    }
};

/*

class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int x:nums) {
            pq.push(x);
            if(pq.size() > size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
};


*/
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */