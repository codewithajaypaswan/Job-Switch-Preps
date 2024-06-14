struct Node {
public:
    int key;
    Node* next;
    Node(int k, Node* n) {
        key = k;
        next = n;
    }
};

class MyHashSet {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};

    int hash(int key) {
        return (int)((long)key * mult % size);
    }

    MyHashSet() {
        
    }
    
    void add(int key) {
        if (contains(key)) return;
        int h = hash(key);
        Node* node = new Node(key, data[h]);
        data[h] = node;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else {
            for (; node->next != NULL; node = node->next) {
                if (node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    delete temp;
                    return;
                }
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return true;
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