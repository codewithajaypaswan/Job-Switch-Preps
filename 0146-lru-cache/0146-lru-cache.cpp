class LRUCache {
public:
    class Node {
        public:
        int val, key;
        Node* next, *prev;
        Node(int key, int val) {
            this->val = val;
            this->key = key;
        }
    };
    int size = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            removeNode(temp);
            addNode(temp);
            mp.erase(key);
            mp[key] = head->next;
            return temp->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            removeNode(mp[key]);
            mp.erase(key);
        }
        else if(size == mp.size()) {
            Node* temp = tail->prev;
            removeNode(temp);
            mp.erase(temp->key);
        }
        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */