class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size = 0;
    MyLinkedList() {
        head = new Node(0);
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* cur = head;
        for(int i=0; i<=index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        Node* temp = head;
        if(index > size) return;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        Node* p1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = p1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */