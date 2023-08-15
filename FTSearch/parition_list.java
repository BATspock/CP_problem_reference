Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


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
    public ListNode partition(ListNode head, int x) {
        //traverse from head
        ListNode lesser = new ListNode();
        ListNode lesser_head = new ListNode();
        lesser_head = lesser;

        ListNode greater = new ListNode();
        ListNode greater_head = new ListNode();
        greater_head = greater;

        ListNode current = new ListNode();

        current = head;

        while (current!=null){

            if (current.val < x){
                ListNode temp = new ListNode(current.val);
                lesser.next = temp;
                lesser = temp;
            }
            else {
                ListNode temp = new ListNode(current.val);
                greater.next = temp;
                greater = temp;
            }
            current= current.next;
        }
        
        //join two halves
        lesser.next = greater_head.next;

        return lesser_head.next;
    }
}
