struct Node {
public:
    int key;
    Node* next;
    Node(int k) {
        key = k;
        next = NULL;
    }
};
class MyHashSet {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};
    int findHash(int key) {
        return ((long)key%size * mult)%size;
    }
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)) return;
        int hash = findHash(key);
        Node* node = new Node(key);
        node->next = data[hash];
        data[hash] = node;
    }
    
    void remove(int key) {
        int hash = findHash(key);
        Node* node = data[hash];
        if(node == NULL) return;
        if(node->key == key) {
            data[hash] = node->next;
            delete node;
            return;
        }
        else {
            while(node->next && node->next->key == key) {
                Node* temp = node->next;
                node->next = temp->next;
                // temp->next = NULL;
                delete temp;
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash = findHash(key);
        Node* node = data[hash];
        while(node) {
            if(node->key == key) return true;
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */