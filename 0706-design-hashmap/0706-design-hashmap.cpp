struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
    }
};
class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val);
        node->next = data[h];
        data[h] = node;
    }    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else {
            while(node->next != NULL) {
                if(node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    return;
                }
                node = node->next;
            }
        }
    }
};