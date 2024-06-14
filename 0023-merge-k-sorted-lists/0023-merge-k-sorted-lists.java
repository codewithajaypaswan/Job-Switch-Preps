/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode merge(ListNode list1, ListNode list2) {
        if(list1 == null) return list2;
        if(list2 == null) return list1;
        if(list1.val < list2.val) {
            list1.next = merge(list1.next, list2);
            return list1;
        }
        else {
            list2.next = merge(list1, list2.next);
            return list2;
        }
    }
    public ListNode solve(ListNode[] lists, int cur) {
        if(lists.length - 1 == cur) return lists[cur];
        ListNode a = solve(lists, cur+1);
        ListNode b = lists[cur];
        a = merge(a, b);
        return a;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        return solve(lists, 0);
    }
}