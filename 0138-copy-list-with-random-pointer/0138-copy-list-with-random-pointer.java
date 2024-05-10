/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node cur = head;
        while(cur != null) {
            Node temp = new Node(cur.val);
            Node nxt = cur.next;
            cur.next = temp;
            temp.next = nxt;
            cur = nxt;
        }
        cur = head;
        while(cur != null) {
            if(cur.random != null) {
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;
        }
        Node dummy = new Node(0);
        Node org = head, dup = dummy;
        while(org != null && dup != null) {
            dup.next = org.next;
            org.next = org.next.next;
            org = org.next;
            dup = dup.next;
        }
        return dummy.next;
    }
}