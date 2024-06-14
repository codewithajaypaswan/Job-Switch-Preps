public class Node {
    int val;
    Node next;
    Node(int val) {
        this.val = val;
        next = null;
    }
}

class MyLinkedList {
    Node head;
    int size;
    public MyLinkedList() {
        size = 0;
        head = new Node(0);
    }
    
    public int get(int index) {
        if(index >= size) return -1;
        Node temp = head;
        for(int i=0; i<=index; i++) {
            temp = temp.next;
        }
        return temp.val;
    }
    
    public void addAtHead(int val) {
        Node temp = head.next;
        head.next = new Node(val);
        head.next.next = temp;
        size++;
    }
    
    public void addAtTail(int val) {
        Node temp = head;
        while(temp.next != null) {
            temp = temp.next;
        }
        temp.next = new Node(val);
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if(index > size) return;
        Node temp = head;
        for(int i=0; i<index; i++) {
            temp = temp.next;
        }
        Node p = temp.next;
        temp.next = new Node(val);
        temp.next.next = p;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if(index >= size) return;
        Node temp = head;
        for(int i=0; i<index; i++) {
            temp = temp.next;
        }
        Node del = temp.next;
        temp.next = del.next;
        del.next = null;
        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */